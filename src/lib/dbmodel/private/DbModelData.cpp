#include <private/DbModelData.h>

DbModelData::DbModelData(const QString& name) :
	_name(name) {
}

DbModelData::DbModelData(const DbModelData& other) :
	QSharedData(other), _name(other.name()) {
}

DbModelData::~DbModelData()
{}
