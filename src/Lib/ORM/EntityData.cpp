#include <Lib/ORM/EntityData.h>

EntityData::EntityData() :
	QSharedData() {
}

EntityData::EntityData(const EntityData& other) :
	QSharedData(other) {
}

EntityData::~EntityData() {
}
