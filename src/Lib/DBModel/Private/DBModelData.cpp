#include <Lib/DBModel/Private/DBModelData.h>

DBModelData::DBModelData(const QString& name) :
	Base(name) {
}

DBModelData::DBModelData(const DBModelData& other) :
	Base(other) {
}

DBModelData::~DBModelData() {
}
