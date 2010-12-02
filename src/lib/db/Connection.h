#ifndef CONNECTION_H
#define CONNECTION_H

#include <QtCore/QObject>
#include <QtCore/QList>
#include <QtSql/QSqlRecord>
#include <QtSql/QSqlQuery>

#include <ConnectionData.h>
#include <Queries.h>

class Connection: public QObject {
  Q_OBJECT;
  
 public:
  Connection(QObject* p=0);
  virtual ~Connection();
  void setConnectionName(const QString& n) { connectionName_ = n; }
  QString connectionName() const { return connectionName_; }

  public slots:
  virtual void onConnectRequest(const ConnectionData& cd, const QString& connName);
  virtual void onDisconnectRequest();
  virtual void execQuery(const QString& sql, const Queries::QueryId& qid);

 signals:
  void connected(const QString& info);
  void disconnected();
  void message(const QString& msg);
  void queryCompleted(const QList<QSqlRecord>& res, const Queries::QueryId& qid);

 protected:
  virtual QSqlQuery exec(const QString& sql);

 private:
  ConnectionData cd_;
  QString connectionName_;
};

#endif // CONNECTION_H
