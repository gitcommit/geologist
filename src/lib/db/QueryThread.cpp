#include <QueryThread.h>

#include <QtCore/QDebug>

#include "Connection.h"

QueryThread::QueryThread(QObject* p)
  : QThread(p),
    abort_(false)
{
  setConnectionName("dbConn");
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
  connect(this, SIGNAL(execQueryRequest(const QString&, const Queries::QueryId&)), &conn_, SLOT(execQuery(const QString&, const Queries::QueryId&)));
  connect(&conn_, SIGNAL(queryCompleted(const QList<QSqlRecord>&, const Queries::QueryId&)), this, SLOT(onQueryCompleted(const QList<QSqlRecord>&, const Queries::QueryId&)));
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

void QueryThread::onQueryCompleted(const QList<QSqlRecord>& res, const Queries::QueryId& qid) {
  emit queryCompleted(res);
  switch(qid) {
  case Queries::CurrentUser: emit currentUserRequestCompleted(extractCurrentUserFromQueryResult(res)); break;
  case Queries::CurrentTimestamp: emit currentTimestampRequestCompleted(extractCurrentTimestampFromQueryResult(res)); break;
  default: break;
  };
}

QString QueryThread::extractCurrentUserFromQueryResult(const QList<QSqlRecord>& res) const {
  Q_ASSERT(!res.isEmpty());
  return res.first().field("CURRENT_USER").value().toString();
}

QDateTime QueryThread::extractCurrentTimestampFromQueryResult(const QList<QSqlRecord>& res) const {
  Q_ASSERT(!res.isEmpty());
  return res.first().field("CURRENT_TIMESTAMP").value().toDateTime();
}

void QueryThread::onCurrentUserRequest() {
  emit execQueryRequest("SELECT CURRENT_USER AS CURRENT_USER", Queries::CurrentUser);
}

void QueryThread::onCurrentTimestampRequest() {
  emit execQueryRequest("SELECT CURRENT_TIMESTAMP AS CURRENT_TIMESTAMP", Queries::CurrentTimestamp);
}
