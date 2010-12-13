#include <EntityData.h>

EntityData::EntityData() :
	QSharedData() {
}

EntityData::EntityData(const EntityData& other) :
	QSharedData(other) {
}

EntityData::~EntityData() {
}
