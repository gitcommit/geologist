#ifndef QueryThread_H
#define QueryThread_H

#include <QtCore/QThread>
#include <QtSql/QSqlRecord>
#include <QtCore/QList>
#include <QtCore/QMutex>

#include <ConnectionData.h>
#include <Connection.h>

class QueryThread: public QThread {
  Q_OBJECT

    public:
  QueryThread(QObject* p = 0);
  virtual ~QueryThread();
  void setConnectionName(const QString& n) { connectionName_ = n; }
  QString connectionName() const { return connectionName_; }

  public slots:
  virtual void open(const ConnectionData& cd);
  virtual void close();
  virtual void abort();
  void onConnectionMessage(const QString& msg);
  void onConnected(const QString& msg);
  void onDisconnected();
  void onExecutionRequest(const QString& sql);

 signals:
  void message(const QString& msg);
  void executionCompleted(const QList<QSqlRecord>& res);
  void connected(const QString& info);
  void disconnected();
  void connectRequest(const ConnectionData& cd, const QString& connectionName);
  void disconnectRequest();
 protected:
  virtual void run();

 private:
  Connection conn_;
  QString connectionName_;
  bool abort_;
  QMutex mutex_;
};

#endif
