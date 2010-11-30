#include <QueryThread.h>

#include <QtCore/QDebug>

#include "Connection.h"

QueryThread::QueryThread(QObject* p)
  : QThread(p),
    conn_(0)
{
}

QueryThread::~QueryThread()
{}

void QueryThread::run() {
  emit message(tr("Running..."));
  qDebug() << connectionName() << " running...";
  connect(&conn_, SIGNAL(message(const QString&)), this, SLOT(onConnectionMessage(const QString&)));
  exec();
}

void QueryThread::open(const ConnectionData& cd) {
  if (!isRunning()) {
    start(LowPriority);
  }
  emit message(tr("Connecting..."));
  conn_.setConnectionName(connectionName());
  conn_.open(cd);
}

void QueryThread::close() {
  emit message(tr("Closing..."));
}

void QueryThread::onConnectionMessage(const QString& msg) {
  emit message(msg);
}

void QueryThread::onExecutionRequest(const QString& sql) {
  conn_.exec(sql);
}
