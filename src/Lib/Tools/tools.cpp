#include <Lib/Tools/tools.h>

App* getApp() {
	return qobject_cast<App*>(QApplication::instance());
}