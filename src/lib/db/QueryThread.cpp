#include <QueryThread.h>

#include <QtCore/QDebug>

#include "Connection.h"

QueryThread::QueryThread(QObject* p)
  : QThread(p),
    abort_(false)
{
  connect(this, SIGNAL(connectRequest(const ConnectionData&, const QString&)), &conn_, SLOT(onConnectRequest(const ConnectionData&, const QString&)));
  connect(this, SIGNAL(disconnectRequest()), &conn_, SLOT(onDisconnectRequest()));
}

QueryThread::~QueryThread()
{
  mutex_.lock();
  abort_ = true;
  mutex_.unlock();
}

void QueryThread::run() {
  emit message(tr("Query Thread Running..."));
  connect(&conn_, SIGNAL(message(const QString&)), this, SLOT(onConnectionMessage(const QString&)));
  connect(&conn_, SIGNAL(connected(const QString&)), this, SLOT(onConnected(const QString&)));
  connect(this, SIGNAL(execQueryRequest(const QString&)), &conn_, SLOT(execQuery(const QString&)));
  connect(&conn_, SIGNAL(disconnected()), this, SLOT(onDisconnected()));
  exec();
}

void QueryThread::open(const ConnectionData& cd) {
  if (!isRunning()) {
    start(LowPriority);
  }
  emit message(tr("Sending Connect Request to Database Connection..."));
  emit connectRequest(cd, connectionName());
}

void QueryThread::close() {
  emit message(tr("Sendig Close Request to Database Connection..."));
  emit disconnectRequest();
}

void QueryThread::onConnectionMessage(const QString& msg) {
  emit message(msg);
}

void QueryThread::onExecutionRequest(const QString& sql) {
  emit execQueryRequest(sql);
}

void QueryThread::abort() {
  mutex_.lock();
  abort_ = true;
  mutex_.unlock();
}

void QueryThread::onConnected(const QString& info) {
  emit connected(info);
}

void QueryThread::onDisconnected() {
  emit disconnected();
}
