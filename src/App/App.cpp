#include <App.h>

#include <QtCore/QDebug>
#include <QtCore/QMetaType>
#include <QtCore/QDateTime>
#include <QtCore/QString>
#include <QtCore/QList>
#include <QtSql/QSqlRecord>

#include <App/config.h>

#include <Lib/DB/QueryThread.h>
#include <Lib/DB/ConnectionData.h>
#include <Lib/DB/TypedQuery.h>

#include <Lib/GUI/DB/DatabaseConnectionDialog.h>

#include <Lib/Model/Core/SIPrefix.h>
#include <Lib/Model/Core/SIPrefixMapper.h>

#include <Lib/ORM/Entity.h>
#include <Lib/Settings/Settings.h>
#include <Lib/DBModel/DbModel.h>

Q_DECLARE_METATYPE(ConnectionData)
Q_DECLARE_METATYPE(TypedQuery)
Q_DECLARE_METATYPE(QList<TypedQuery>)
Q_DECLARE_METATYPE(QDateTime)
Q_DECLARE_METATYPE(QString)
Q_DECLARE_METATYPE(QSqlRecord)
Q_DECLARE_METATYPE(QList<QSqlRecord>)

App::App(int argc, char** argv)
: QApplication(argc, argv), _siPrefixMapper(0), lastQueryId_(0), _dbModel(0)
{
  setApplicationVersion(APP_VERSION);
  setApplicationName(APP_NAME);
  setOrganizationDomain(ORG_DOMAIN);
  setOrganizationName(ORG_NAME);
  registerMetatypes();
  init();
}

void App::registerMetatypes() {
  qRegisterMetaType<ConnectionData>("ConnectionData");
  qRegisterMetaType<QList<QSqlRecord> >("QList<QSqlRecord>");
  qRegisterMetaType<TypedQuery>("TypedQuery");
  qRegisterMetaType<QList<TypedQuery> >("QList<TypedQuery>"); 
  qRegisterMetaType<QDateTime>("QDateTime");
  qRegisterMetaType<QString>("QString>");
  qRegisterMetaType<QList<QSqlRecord> >("QList<QSqlRecord>");
}

void App::init() {
	Settings s(this);
	s.load(&cd_);
	_siPrefixMapper = new SIPrefixMapper(this);
	_dbModel.setName(DB_NAME);
	_dbModel.loadFromFile(DB_CONFIG_FILE);
	  
	connect(&dbThread_, SIGNAL(queryCompleted(const TypedQuery&)), siPrefixMapper(), SLOT(onQueryCompleted(const TypedQuery&)));
	connect(siPrefixMapper(), SIGNAL(loaded(const QList<SIPrefix*>&)), this, SLOT(onSIPrefixesLoaded(const QList<SIPrefix*>&)));
	connect(siPrefixMapper(), SIGNAL(queryRequest(const TypedQuery&)), &dbThread_, SLOT(onExecRequest(const TypedQuery&)));
	
	connect(&dbThread_, SIGNAL(message(const QString&)), this, SLOT(onDatabaseMessage(const QString&)));
	connect(&dbThread_, SIGNAL(connected(const QString&)), this, SLOT(onConnected(const QString&)));
	connect(&dbThread_, SIGNAL(disconnected()), this, SLOT(onDisconnected()));
	
	connect(this, SIGNAL(connectRequest(const ConnectionData&)), &dbThread_, SLOT(open(const ConnectionData&)));
	connect(this, SIGNAL(disconnectRequest()), &dbThread_, SLOT(close()));
	connect(this, SIGNAL(beginRequest()), &dbThread_, SLOT(onBeginRequest()));
	connect(this, SIGNAL(commitRequest()), &dbThread_, SLOT(onCommitRequest()));
	connect(this, SIGNAL(rollbackRequest()), &dbThread_, SLOT(onRollbackRequest()));
	connect(this, SIGNAL(savepointRequest(const QString&)), &dbThread_, SLOT(onSavepointRequest(const QString&)));
	connect(this, SIGNAL(rollbackToSavepointRequest(const QString&)), &dbThread_, SLOT(onRollbackToSavepointRequest(const QString&)));
	connect(this, SIGNAL(queryRequest(const QList<TypedQuery>&)), &dbThread_, SLOT(onExecRequest(const QList<TypedQuery>&)));
	connect(this, SIGNAL(queryRequest(const TypedQuery&)), &dbThread_, SLOT(onExecRequest(const TypedQuery&)));
}

App::~App()
{
  dbThread_.quit();
  dbThread_.wait();
}

void App::debug(const QString& msg) {
  emit debugMessage(tr("Debug: %1").arg(msg));
}

void App::onOpenDb() {
	Settings s(this);
	DatabaseConnectionDialog* d = new DatabaseConnectionDialog(activeWindow(), &cd_);
	if (QDialog::Accepted != d->exec()) {
		s.load(&cd_);
		return;
	}
	s.save(&cd_);
  emit connectRequest(cd_);
}

void App::onCloseDb() {
  emit disconnectRequest();
}

void App::onDatabaseMessage(const QString& msg) {
  emit databaseMessage(msg);
}

void App::onConnected(const QString& msg) {
  emit databaseMessage(tr("Connected: %1").arg(msg));
  emit databaseOpened(msg);
  /*currentUserQueryId_ = nextQueryId();
  emit beginRequest();
  emit queryRequest(TypedQuery("SELECT CURRENT_USER AS CURRENT_USER;", currentUserQueryId_));
  */
  emit debugMessage(tr("\n-- CREATE DATABASE script --\n%1\n-- end of CREATE DATABASE script.\n")
		  .arg(_dbModel.create().join("\n")));
  emit beginRequest();
  _siPrefixMapper->testLoad();
}

void App::onDisconnected() {
  emit databaseMessage(tr("Disconnected."));
  emit databaseClosed();
}
void App::onSIPrefixesLoaded(const QList<SIPrefix*>& lst) {
	emit debugMessage(tr("App::onSIPrefixesLoaded(...)"));
	for (QList<SIPrefix*>::const_iterator it = lst.begin(); it != lst.end(); it++) {
		emit debugMessage(tr("Loaded SI Prefix: %1").arg((*it)->toString()));
	}
}
