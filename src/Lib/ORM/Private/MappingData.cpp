#include <Lib/ORM/Private/MappingData.h>

#include <Lib/DBModel/Table.h>

MappingData::MappingData(Table* t) :
	QSharedData(), _table(t) {
	setTable(t);
}

MappingData::MappingData(const MappingData& other) :
	QSharedData(other), _table(other._table) {
}

MappingData::~MappingData() {
}
