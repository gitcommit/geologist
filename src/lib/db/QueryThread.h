#ifndef QueryThread_H
#define QueryThread_H

#include <QtCore/QThread>

#include <ConnectionData.h>

class Connection;

class QueryThread: public QThread {
  Q_OBJECT
    public:
  QueryThread(QObject* p = 0,
	      const QString& name = QString("Query Thread"));
  virtual ~QueryThread();
  virtual void run();
  virtual void open(const ConnectionData& cd);
  virtual void close();
  public slots:
  void onConnectionMessage(const QString& msg);
 signals:
  void message(const QString& msg);
 protected:
 private:
  Connection* conn_;
};

#endif
