#include <Lib/DB/QueryThread.h>

#include <QtCore/QDebug>

#include <Lib/DB/Connection.h>

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
  connect(&conn_, SIGNAL(disconnected()), this, SLOT(onDisconnected()));
  connect(&conn_, SIGNAL(queryCompleted(const TypedQuery&)), this, SLOT(onQueryCompleted(const TypedQuery&)));
  
  connect(this, SIGNAL(execRequest(const QList<TypedQuery>&)), &conn_, SLOT(onExecRequest(const QList<TypedQuery>&)));
  connect(this, SIGNAL(execRequest(const TypedQuery&)), &conn_, SLOT(onExecRequest(const TypedQuery&)));
  connect(this, SIGNAL(beginRequest()), &conn_, SLOT(onBeginRequest()));
  connect(this, SIGNAL(commitRequest()), &conn_, SLOT(onCommitRequest()));
  connect(this, SIGNAL(rollbackRequest()), &conn_, SLOT(onRollbackRequest()));
  connect(this, SIGNAL(savepointRequest(const QString&)), &conn_, SLOT(onSavepointRequest(const QString&)));
  connect(this, SIGNAL(rollbackToSavepointRequest(const QString&)), &conn_, SLOT(onRollbackToSavepointRequest(const QString&)));
  
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

void QueryThread::onBeginRequest() {
	emit beginRequest();
}

void QueryThread::onCommitRequest() {
	emit commitRequest();
}

void QueryThread::onRollbackRequest() {
	emit rollbackRequest();
}

void QueryThread::onSavepointRequest(const QString& name) {
	emit savepointRequest(name);
}

void QueryThread::onRollbackToSavepointRequest(const QString& name) {
	emit rollbackToSavepointRequest(name);
}

void QueryThread::onExecRequest(const QList<TypedQuery>& lst) {
	emit execRequest(lst);
}

void QueryThread::onExecRequest(const TypedQuery& q) {
	emit execRequest(q);
}

void QueryThread::onQueryCompleted(const TypedQuery& q) {
	emit queryCompleted(q);
}