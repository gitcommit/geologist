#include <App.h>

int main(int argc, char** argv) {
  App* a = new App(argc, argv);
  a->exec();
  delete a;
  return 1;
}
