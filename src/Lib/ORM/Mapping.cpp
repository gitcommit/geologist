#include <Lib/ORM/Mapping.h>

#include <Lib/ORM/Private/MappingData.h>

Mapping::Mapping(QObject* p) :
	QObject(p), _d(0) {
	_d = new MappingData();
}

Mapping::Mapping(const Mapping& other) :
	_d(0) {
}

Mapping::~Mapping() {
}

void Mapping::setTable(Table* t) {
	_d->setTable(t);
}

Table* Mapping::table() const {
	return _d->table();
}