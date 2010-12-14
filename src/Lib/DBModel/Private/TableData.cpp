#include <Lib/DBModel/private/TableData.h>

TableData::TableData(const QString& name) :
	Base(name) {
}

TableData::TableData(const TableData& other) :
	Base(other) {
}

TableData::~TableData() {
}
