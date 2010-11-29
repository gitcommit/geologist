#include <Connection.h>

#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlError>

#include <QtCore/QVariant>
#include <QtCore/QDebug>
#include <QtGui/QApplication>

#include <ConnectionData.h>

Connection::Connection(QObject* p, const QString& name)
  : QObject(p) {
  setObjectName(name);
}

Connection::~Connection() {
  close();
}

void Connection::open(const ConnectionData& cd) {
  cd_ = cd;
  emit message(tr("Connecting to %1 ...").arg(cd_.info()));
  QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL", objectName());
  db.setHostName(cd_.host());
  db.setPort(QVariant(cd_.port()).toInt());
  db.setDatabaseName(cd_.database());
  db.setUserName(cd_.login());
  db.setPassword(cd_.password());
  bool isConn = db.open();
  emit message(tr("Connection result: %1").arg(isConn));
  QApplication::instance()->processEvents();
  if (!isConn) {
    emit message(tr("Connection failed: %1").arg(db.lastError().text()));
    return;
  }
  emit message(tr("Connected to %1").arg(cd_.info()));
}

void Connection::close() {
  emit message(tr("Closing..."));
  QSqlDatabase::database(objectName()).close();
  emit message(tr("Closed."));
}

void Connection::onExecutionRequest(const QString& sql) {
  emit message(tr("Execution request: %1").arg(sql));
}
