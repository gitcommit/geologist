#include <Lib/DBModel/Private/DataTypeData.h>

DataTypeData::DataTypeData(const QString& name, const QString& sqlName, const bool& requiresQuoting) :
	Base(name), _sqlName(sqlName), _requiresQuoting(requiresQuoting) {
}

DataTypeData::DataTypeData(const DataTypeData& other) :
	Base(other), _sqlName(other._sqlName), _requiresQuoting(other._requiresQuoting) {
}

DataTypeData::~DataTypeData() {
}
