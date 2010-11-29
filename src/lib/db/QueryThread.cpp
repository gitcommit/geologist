#include <QueryThread.h>

#include <QtCore/QDebug>

#include "Connection.h"

QueryThread::QueryThread(QObject* p, const QString& name)
  : QThread(p),
    conn_(0)
{
  setObjectName(name);
  run();
}

QueryThread::~QueryThread()
{}

void QueryThread::run() {
  emit message(tr("Running..."));
  conn_ = new Connection(this, QString("db_conn_%1").arg(objectName()));
  connect(conn_, SIGNAL(message(const QString&)), this, SLOT(onConnectionMessage(const QString&)));
}

void QueryThread::open(const ConnectionData& cd) {
  emit message(tr("Connecting..."));
  conn_->open(cd);
}

void QueryThread::close() {
  emit message(tr("Closing..."));
}

void QueryThread::onConnectionMessage(const QString& msg) {
  emit message(msg);
}
