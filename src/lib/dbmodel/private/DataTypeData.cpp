#include <private/DataTypeData.h>

DataTypeData::DataTypeData(const QString& name, const QString& sqlName) :
	Base(name), _sqlName(sqlName) {
}

DataTypeData::DataTypeData(const DataTypeData& other) :
	Base(other), _sqlName(other._sqlName) {
}

DataTypeData::~DataTypeData() {
}
