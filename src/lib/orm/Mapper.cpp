#include <Mapper.h>

Mapper::Mapper(QObject* p) :
	QObject(p) {
}

Mapper::~Mapper() {
}

void Mapper::onQueryCompleted(const TypedQuery& q) {
}