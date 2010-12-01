#ifndef App_H
#define App_H

#include <QtGui/QApplication>
#include <QtCore/QString>

#include <ConnectionData.h>

#include <QueryThread.h>
 
class App: public QApplication {
  Q_OBJECT
    public:
  App(int argc, char** argv);
  virtual ~App();
  void init();
 signals:
  void connectRequest(const ConnectionData& cd);
  void disconnectRequest();
  void databaseOpened(const QString& info);
  void databaseClosed();
  void databaseMessage(const QString& msg);
  public slots:
  virtual void debug(const QString& msg);
  virtual void openDb();
  virtual void closeDb();
  void onDatabaseMessage(const QString& msg);
  void onConnected(const QString& msg);
  void onDisconnected();
 protected:
  virtual void registerMetatypes();
 private:
  QueryThread dbThread_;

  ConnectionData cd_;
};

#endif
