#ifndef QueryThread_H
#define QueryThread_H

#include <QtCore/QThread>
#include <QtSql/QSqlRecord>
#include <QtCore/QList>

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
  void onConnectionMessage(const QString& msg);
  void onExecutionRequest(const QString& sql);
 signals:
  void message(const QString& msg);
  void executionCompleted(const QList<QSqlRecord>& res);
 protected:
  virtual void run();
 private:
  Connection conn_;
  QString connectionName_;
};

#endif
