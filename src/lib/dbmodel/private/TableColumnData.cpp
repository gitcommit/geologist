#include <private/TableColumnData.h>

TableColumnData::TableColumnData(const QString& name, DataType* dataType) :
	Base(name), _dataType(dataType) {
}

TableColumnData::TableColumnData(const TableColumnData& other) :
	Base(other) {
}

TableColumnData::~TableColumnData() {
}
