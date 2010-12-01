#include <App.h>

#include <QtCore/QDebug>
#include <QtCore/QMetaType>

#include <config.h>

#include <QueryThread.h>
#include <ConnectionData.h>

#include <SIPrefix.h>
#include <Entity.h>

Q_DECLARE_METATYPE(ConnectionData);
Q_DECLARE_METATYPE(Entity);
Q_DECLARE_METATYPE(SIPrefix);

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
}

void App::init() {
  cd_.setHost("localhost");
  cd_.setPort("5433");
  cd_.setDatabase("test");
  cd_.setLogin("jolo");
  cd_.setPassword("nix");
  dbThread_.setConnectionName("dbconn");
  connect(&dbThread_, SIGNAL(message(const QString&)), this, SLOT(onDatabaseMessage(const QString&)));
  connect(&dbThread_, SIGNAL(connected(const QString&)), this, SLOT(onConnected(const QString&)));
  connect(&dbThread_, SIGNAL(disconnected()), this, SLOT(onDisconnected()));
  connect(this, SIGNAL(connectRequest(const ConnectionData&)), &dbThread_, SLOT(open(const ConnectionData&)));
  connect(this, SIGNAL(disconnectRequest()), &dbThread_, SLOT(close()));
}

App::~App()
{
  dbThread_.quit();
  dbThread_.wait();
}

void App::debug(const QString& msg) {
  qDebug() << msg;
}

void App::openDb() {
  emit connectRequest(cd_);
}

void App::closeDb() {
  emit disconnectRequest();
}

void App::onDatabaseMessage(const QString& msg) {
  debug(tr("Database: %1").arg(msg));
  emit databaseMessage(msg);
}

void App::onConnected(const QString& msg) {
  emit databaseMessage(tr("Connected: %1").arg(msg));
  emit databaseOpened(msg);
}

void App::onDisconnected() {
  emit databaseMessage(tr("Disconnected."));
  emit databaseClosed();
}
