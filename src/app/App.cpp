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
  : QApplication(argc, argv, false)
{
  setApplicationVersion(APP_VERSION);
  setApplicationName(APP_NAME);
  setOrganizationDomain(ORG_DOMAIN);
  setOrganizationName(ORG_NAME);
  registerMetatypes();
  init();
  openDb();
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
  reader_.setConnectionName("reader");
  writer_.setConnectionName("writer");
  connect(&reader_, SIGNAL(message(const QString&)), this, SLOT(onReaderMessage(const QString&)));
  connect(&writer_, SIGNAL(message(const QString&)), this, SLOT(onWriterMessage(const QString&)));
  connect(this, SIGNAL(connectRequest(const ConnectionData&)), &reader_, SLOT(open(const ConnectionData&)));
  connect(this, SIGNAL(connectRequest(const ConnectionData&)), &writer_, SLOT(open(const ConnectionData&)));
  connect(this, SIGNAL(disconnectRequest()), &reader_, SLOT(close()));
  connect(this, SIGNAL(disconnectRequest()), &writer_, SLOT(close()));
}

App::~App()
{/*
   if (reader_) {
   reader_->quit();
   reader_->wait();
   delete reader_;
   }
   if (writer_) {
   writer_->quit();
   writer_->wait();
   delete writer_;
   }*/
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

void App::onReaderMessage(const QString& msg) {
  debug(tr("Reader: %1").arg(msg));
}

void App::onWriterMessage(const QString& msg) {
  debug(tr("Writer: %1").arg(msg));
}
