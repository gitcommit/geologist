#include <Lib/ORM/TableMapping.h>
#include <Lib/ORM/Private/MappingData.h>

TableMapping::TableMapping(QObject* p, Table* t) :
	Mapping(p) {
	setTable(t);
}

TableMapping::TableMapping(const TableMapping& other) :
	Mapping(other) {
}

TableMapping::~TableMapping() {
}

void TableMapping::setTable(Table* t) {
	_d->setTable(t);
}