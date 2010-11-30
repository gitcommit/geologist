#ifndef CONNECTION_H
#define CONNECTION_H

#include <QtCore/QObject>
#include <QtCore/QList>
#include <QtSql/QSqlRecord>

#include <ConnectionData.h>

class Connection: public QObject {
  Q_OBJECT
    public:
  Connection(QObject* p=0);
  virtual ~Connection();
  void exec(const QString& sql);
  void setConnectionName(const QString& n) { connectionName_ = n; }
  QString connectionName() const { return connectionName_; }
 public slots:
  virtual void open(const ConnectionData& cd);
  virtual void close();
 signals:
  void message(const QString& msg);
  void queryCompleted(const QList<QSqlRecord>& res);
 private:
  ConnectionData cd_;
  QString connectionName_;
};

#endif // CONNECTION_H
