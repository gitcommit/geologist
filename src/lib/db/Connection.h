#ifndef CONNECTION_H
#define CONNECTION_H

#include <QtCore/QObject>

#include <ConnectionData.h>

class Connection: public QObject {
  Q_OBJECT
    public:
  Connection(QObject* p, const QString& name);
  virtual ~Connection();
 public slots:
  void onExecutionRequest(const QString& sql);
 signals:
  void message(const QString& msg);
  public slots:
  virtual void open(const ConnectionData& cd);
  virtual void close();
 private:
  ConnectionData cd_;
};

#endif // CONNECTION_H
