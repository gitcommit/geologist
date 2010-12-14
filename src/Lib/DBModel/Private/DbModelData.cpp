#include <Lib/DBModel/private/DbModelData.h>

DbModelData::DbModelData(const QString& name) :
	Base(name) {
}

DbModelData::DbModelData(const DbModelData& other) :
	Base(other) {
}

DbModelData::~DbModelData() {
}
