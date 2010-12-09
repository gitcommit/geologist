#include <Mapper.h>

Mapper::Mapper(QObject* p) :
	QObject(p) {
}

Mapper::~Mapper() {
}

void Mapper::onQueryCompleted(const TypedQuery& q) {
}

qlonglong Mapper::nextQueryId() {
	return (qobject_cast<App*>(QApplication::instance())).nextQueryId();
}