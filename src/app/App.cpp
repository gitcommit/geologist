#include <App.h>

#include <QtCore/QDebug>
#include <QtCore/QMetaType>
#include <QtCore/QDateTime>
#include <QtCore/QString>
#include <QtCore/QList>
#include <QtSql/QSqlRecord>

#include <config.h>

#include <QueryThread.h>
#include <ConnectionData.h>

#include <DatabaseConnectionDialog.h>

#include <SIPrefix.h>
#include <SIPrefixMapper.h>

#include <Entity.h>
#include <Queries.h>
#include <Settings.h>

Q_DECLARE_METATYPE(ConnectionData)
Q_DECLARE_METATYPE(Entity)
Q_DECLARE_METATYPE(SIPrefix)
Q_DECLARE_METATYPE(Queries)
Q_DECLARE_METATYPE(QDateTime)
Q_DECLARE_METATYPE(QString)
Q_DECLARE_METATYPE(QSqlRecord)
Q_DECLARE_METATYPE(QList<QSqlRecord>)

App::App(int argc, char** argv)
: QApplication(argc, argv), siPrefixMapper_(0)
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
  qRegisterMetaType<SIPrefix>("SIPrefix");
  qRegisterMetaType<QList<SIPrefix> >("QList<SIPrefix>");
  qRegisterMetaType<Entity>("Entity");
  qRegisterMetaType<QList<QSqlRecord> >("QList<QSqlRecord>");
  qRegisterMetaType<Queries>("Queries");
  qRegisterMetaType<QDateTime>("QDateTime");
  qRegisterMetaType<QString>("QString>");
  qRegisterMetaType<QList<QSqlRecord> >("QList<QSqlRecord>");
}

void App::init() {
	Settings s(this);
	s.load(&cd_);
	siPrefixMapper_ = new SIPrefixMapper(this);
	connect(&dbThread_, SIGNAL(queryCompleted(const QList<QSqlRecord>&, const Queries::QueryId&)), siPrefixMapper_, SLOT(onQueryCompleted(const QList<QSqlRecord>&, const Queries::QueryId&)));
	connect(siPrefixMapper(), SIGNAL(loaded(const QList<SIPrefix>&)), this, SLOT(onSIPrefixesLoaded(const QList<SIPrefix>&)));
	
	connect(&dbThread_, SIGNAL(message(const QString&)), this, SLOT(onDatabaseMessage(const QString&)));
	connect(&dbThread_, SIGNAL(connected(const QString&)), this, SLOT(onConnected(const QString&)));
	connect(&dbThread_, SIGNAL(disconnected()), this, SLOT(onDisconnected()));
	connect(&dbThread_, SIGNAL(queryCompleted(const QList<QSqlRecord>&, const Queries::QueryId&)), this, SLOT(onQueryCompleted(const QList<QSqlRecord>&, const Queries::QueryId&)));
	connect(&dbThread_, SIGNAL(queryCompleted(const TypedQuery&)), this, SLOT(onQueryCompleted(const TypedQuery&)));
	
	connect(this, SIGNAL(connectRequest(const ConnectionData&)), &dbThread_, SLOT(open(const ConnectionData&)));
	connect(this, SIGNAL(disconnectRequest()), &dbThread_, SLOT(close()));
	connect(this, SIGNAL(beginRequest()), &dbThread_, SLOT(onBeginRequest()));
	connect(this, SIGNAL(commitRequest()), &dbThread_, SLOT(onCommitRequest()));
	connect(this, SIGNAL(rollbackRequest()), &dbThread_, SLOT(onRollbackRequest()));
	connect(this, SIGNAL(savepointRequest(const QString&)), &dbThread_, SLOT(onSavepointRequest(const QString&)));
	connect(this, SIGNAL(rollbackToSavepointRequest(const QString&)), &dbThread_, SLOT(onRollbackToSavepointRequest(const QString&)));
	connect(this, SIGNAL(queryRequest(const QString&, const Queries::QueryId&)), &dbThread_, SLOT(onQueryRequest(const QString&, const Queries::QueryId&)));
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
  emit queryRequest("SELECT CURRENT_USER AS CURRENT_USER;", Queries::CurrentUser);
  emit queryRequest("SELECT CURRENT_TIMESTAMP AS CURRENT_TIMESTAMP;", Queries::CurrentTimestamp);
  emit queryRequest(TypedQuery("SELECT CURRENT_USER AS CURRENT_USER;", Queries::CurrentUser));
}

void App::onDisconnected() {
  emit databaseMessage(tr("Disconnected."));
  emit databaseClosed();
}

void App::onQueryCompleted(const QList<QSqlRecord>& res, const Queries::QueryId& qid) {
	switch(qid) {
	case(Queries::CurrentUser): emit debugMessage("Current User recieved"); break;
	case(Queries::CurrentTimestamp): emit debugMessage("Current Timestamp recieved"); break;
	default: emit debugMessage(tr("QueryId %1 not implemented in App::onQueryCompleted()").arg(qid));
	}
}

void App::onSIPrefixesLoaded(const QList<SIPrefix>& lst) {
	for (QList<SIPrefix>::const_iterator it = lst.begin(); it != lst.end(); it++) {
		emit debugMessage(tr("Loaded SI Prefix: %1").arg((*it).toString()));
	}
}

void App::onQueryCompleted(const TypedQuery& q) {
	emit debugMessage(tr("Typed Query Completed."));
	QList<QSqlRecord> res = q.results();
	switch(q.queryId()) {
	case(Queries::CurrentUser): {
		for (QList<QSqlRecord>::const_iterator i = res.begin(); i != res.end(); i++) {
			emit debugMessage(tr("Current User: %1").arg((*i).field("CURRENT_USER").value().toString()));
		}
		break;
	}
	default: {
		emit debugMessage(tr("App::onQueryCompleted(const TypedQuery&): parsing queries of type %1 not yet implented.").arg(q.queryId()));
	}
	}
}