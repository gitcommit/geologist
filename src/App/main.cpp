#include <QtCore/QObject>

#include <App/App.h>
#include <Lib/GUI/Widgets/MainWindow.h>

int main(int argc, char** argv) {
  App* a = new App(argc, argv);
  MainWindow* w = new MainWindow();
  w->show();
  int ret = a->exec();
  delete w;
  delete a;
  return ret;
}
