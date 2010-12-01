#include <Connection.h>

#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlError>
#include <QtSql/QSqlQuery>

#include <QtCore/QVariant>
#include <QtCore/QDebug>
#include <QtGui/QApplication>

#include <ConnectionData.h>

Connection::Connection(QObject* p)
  : QObject(p) {
}

Connection::~Connection() {
  onDisconnectRequest();
}

void Connection::onConnectRequest(const ConnectionData& cd, const QString& connName) {
  cd_ = cd;
  setConnectionName(connName);
  emit message(tr("Connecting to %1 ... as connection %2").arg(cd_.info()).arg(connectionName()));
  QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL", connectionName());
  db.setHostName(cd_.host());
  db.setPort(QVariant(cd_.port()).toInt());
  db.setDatabaseName(cd_.database());
  db.setUserName(cd_.login());
  db.setPassword(cd_.password());
  bool isConn = db.open();
  if (!isConn) {
    emit message(tr("Connection failed: %1").arg(db.lastError().text()));
    QSqlDatabase::removeDatabase(connectionName());
    emit disconnected();
    return;
  }
  emit message(tr("Connected to %1 as %2").arg(cd_.info()).arg(connectionName()));
  emit connected(cd_.info());
}

void Connection::onDisconnectRequest() {
  emit message(tr("Closing..."));
  QSqlDatabase::database(connectionName()).close();
  QSqlDatabase::removeDatabase(connectionName());
  emit message(tr("Closed."));
  emit disconnected();
} 

void Connection::exec(const QString& sql) {
  emit message(tr("exec: %1").arg(sql));
  QSqlQuery q(sql, QSqlDatabase::database(objectName()));
  QList<QSqlRecord> ret;
  while(q.next()) {
    ret.append(q.record());
  }
  q.finish();
  emit queryCompleted(ret);
}
