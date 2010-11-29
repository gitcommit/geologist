#ifndef App_H
#define App_H

#include <QtGui/QApplication>
#include <QtCore/QString>

#include <ConnectionData.h>

class QueryThread;
 
class App: public QApplication {
  Q_OBJECT
    public:
  App(int argc, char** argv);
  virtual ~App();
  void init();
  public slots:
  virtual void debug(const QString& msg);
  virtual void openDb();
  virtual void closeDb();
  void onReaderMessage(const QString& msg);
  void onWriterMessage(const QString& msg);
 protected:
 private:
  QueryThread* reader_;
  QueryThread* writer_;

  ConnectionData cd_;
};

#endif
