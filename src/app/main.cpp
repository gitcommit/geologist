#include <QtCore/QObject>

#include <App.h>
#include <MainWindow.h>

int main(int argc, char** argv) {
  App* a = new App(argc, argv);
  MainWindow* w = new MainWindow();
  QObject::connect(a, SIGNAL(databaseMessage(const QString&)), w, SLOT(onDatabaseMessage(const QString&)));
  QObject::connect(a, SIGNAL(databaseOpened(const QString&)), w, SLOT(onDatabaseOpened(const QString&)));
  QObject::connect(a, SIGNAL(databaseClosed()), w, SLOT(onDatabaseClosed()));
  w->show();
  int ret = a->exec();
  delete w;
  delete a;
  return ret;
}
