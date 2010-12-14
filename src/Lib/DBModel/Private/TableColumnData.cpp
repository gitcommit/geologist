#include <Lib/DBModel/Private/TableColumnData.h>

TableColumnData::TableColumnData(const QString& name, DataType* dataType, const bool& nullable) :
	Base(name), _dataType(dataType), _nullable(nullable) {
}

TableColumnData::TableColumnData(const TableColumnData& other) :
	Base(other), _dataType(other._dataType), _nullable(other._nullable) {
}

TableColumnData::~TableColumnData() {
}
