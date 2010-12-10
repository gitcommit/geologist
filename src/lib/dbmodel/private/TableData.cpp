#include <private/TableData.h>

TableData::TableData(const QString& name) :
	_name(name) {
}

TableData::TableData(const TableData& other) :
	QSharedData(other), _name(other._name) {
}

TableData::~TableData() {
}
