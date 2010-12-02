#include <App.h>

#include <QtCore/QDebug>
#include <QtCore/QMetaType>
#include <QtCore/QDateTime>
#include <QtCore/QString>

#include <config.h>

#include <QueryThread.h>
#include <ConnectionData.h>

#include <DatabaseConnectionDialog.h>

#include <SIPrefix.h>
#include <Entity.h>
#include <Queries.h>
#include <Settings.h>

Q_DECLARE_METATYPE(ConnectionData)
Q_DECLARE_METATYPE(Entity)
Q_DECLARE_METATYPE(SIPrefix)
Q_DECLARE_METATYPE(Queries)
Q_DECLARE_METATYPE(QDateTime)
Q_DECLARE_METATYPE(QString)

App::App(int argc, char** argv)
: QApplication(argc, argv)
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
  qRegisterMetaType<Entity>("Entity");
  qRegisterMetaType<QList<QSqlRecord> >("QList<QSqlRecord>");
  qRegisterMetaType<Queries>("Queries");
  qRegisterMetaType<QDateTime>("QDateTime");
  qRegisterMetaType<QString>("QString>");
}

void App::init() {
	Settings s(this);
	s.load(&cd_);
	connect(&dbThread_, SIGNAL(message(const QString&)), this, SLOT(onDatabaseMessage(const QString&)));
	connect(&dbThread_, SIGNAL(connected(const QString&)), this, SLOT(onConnected(const QString&)));
	connect(&dbThread_, SIGNAL(disconnected()), this, SLOT(onDisconnected()));
	connect(&dbThread_, SIGNAL(currentUserRequestCompleted(const QString&)), this, SLOT(onCurrentUserRequestCompleted(const QString&)));
	connect(&dbThread_, SIGNAL(currentTimestampRequestCompleted(const QDateTime&)), this, SLOT(onCurrentTimestampRequestCompleted(const QDateTime&)));
	connect(this, SIGNAL(currentUserRequest()), &dbThread_, SLOT(onCurrentUserRequest()));
	connect(this, SIGNAL(currentTimestampRequest()), &dbThread_, SLOT(onCurrentTimestampRequest()));
	connect(this, SIGNAL(connectRequest(const ConnectionData&)), &dbThread_, SLOT(open(const ConnectionData&)));
	connect(this, SIGNAL(disconnectRequest()), &dbThread_, SLOT(close()));
	connect(this, SIGNAL(currentUserRequest()), &dbThread_, SLOT(onCurrentUserRequest()));
	connect(this, SIGNAL(currentTimestampRequest()), &dbThread_, SLOT(onCurrentTimestampRequest()));
}

App::~App()
{
  dbThread_.quit();
  dbThread_.wait();
}

void App::debug(const QString& msg) {
  qDebug() << msg;
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
  debug(tr("Database: %1").arg(msg));
  emit databaseMessage(msg);
}

void App::onConnected(const QString& msg) {
  emit databaseMessage(tr("Connected: %1").arg(msg));
  emit databaseOpened(msg);
  emit currentUserRequest();
  emit currentTimestampRequest();
}

void App::onDisconnected() {
  emit databaseMessage(tr("Disconnected."));
  emit databaseClosed();
}

void App::onCurrentUserRequestCompleted(const QString& usr) {
  debug(tr("current user: %1").arg(usr));
}

void App::onCurrentTimestampRequestCompleted(const QDateTime& ts) {
  debug(tr("current timestamp: %1").arg(ts.toString()));
}
