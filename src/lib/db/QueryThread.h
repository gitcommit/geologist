#ifndef QueryThread_H
#define QueryThread_H

#include <QtCore/QThread>
#include <QtCore/QList>
#include <QtCore/QMutex>
#include <QtCore/QDateTime>

#include <QtSql/QSqlRecord>
#include <QtSql/QSqlField>

#include <ConnectionData.h>
#include <Connection.h>
#include <Queries.h>

class QueryThread: public QThread {
  Q_OBJECT;

 public:
  QueryThread(QObject* p = 0);
  virtual ~QueryThread();

  public slots:
  virtual void open(const ConnectionData& cd);
  virtual void close();
  virtual void abort();
  void onConnectionMessage(const QString& msg);
  void onConnected(const QString& msg);
  void onDisconnected();
  void onCurrentUserRequest();
  void onCurrentTimestampRequest();
  void onQueryCompleted(const QList<QSqlRecord>& res, const Queries::QueryId& qid);
 signals:
  void execQueryRequest(const QString& sql, const Queries::QueryId& qid);

  void currentUserRequestCompleted(const QString& usr);
  void currentTimestampRequestCompleted(const QDateTime& ts);

  void message(const QString& msg);
  void queryCompleted(const QList<QSqlRecord>& res);
  void connected(const QString& info);
  void disconnected();
  void connectRequest(const ConnectionData& cd, const QString& connectionName);
  void disconnectRequest();
 protected:
  virtual void run();
  QString connectionName() const { return connectionName_; }
  virtual QString extractCurrentUserFromQueryResult(const QList<QSqlRecord>& res) const;
  virtual QDateTime extractCurrentTimestampFromQueryResult(const QList<QSqlRecord>& res) const;
 private:
  void setConnectionName(const QString& n) { connectionName_ = n; }
  Connection conn_;
  QString connectionName_;
  bool abort_;
  QMutex mutex_;
};

#endif
