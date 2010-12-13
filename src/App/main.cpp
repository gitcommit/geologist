#include <QtCore/QObject>

#include <App.h>
#include <MainWindow.h>

int main(int argc, char** argv) {
  App* a = new App(argc, argv);
  MainWindow* w = new MainWindow();
  w->show();
  int ret = a->exec();
  delete w;
  delete a;
  return ret;
}
