#include <App.h>

#include <QtCore/QDebug>

#include <config.h>

#include <QueryThread.h>
#include <ConnectionData.h>

App::App(int argc, char** argv)
  : QApplication(argc, argv, false),
    reader_(0),
    writer_(0)
{
  setApplicationVersion(APP_VERSION);
  setApplicationName(APP_NAME);
  setOrganizationDomain(ORG_DOMAIN);
  setOrganizationName(ORG_NAME);
  init();
  openDb();
}

void App::init() {
  cd_.setHost("localhost");
  cd_.setPort("5433");
  cd_.setDatabase("test");
  cd_.setLogin("jolo");
  cd_.setPassword("nix");
  reader_ = new QueryThread(this, "reader");
  writer_ = new QueryThread(this, "writer");
  connect(reader_, SIGNAL(message(const QString&)), this, SLOT(onReaderMessage(const QString&)));
  connect(writer_, SIGNAL(message(const QString&)), this, SLOT(onWriterMessage(const QString&)));
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
  reader_->open(cd_);
  writer_->open(cd_);
}

void App::closeDb() {
}

void App::onReaderMessage(const QString& msg) {
  debug(tr("Reader: %1").arg(msg));
}

void App::onWriterMessage(const QString& msg) {
  debug(tr("Writer: %1").arg(msg));
}
