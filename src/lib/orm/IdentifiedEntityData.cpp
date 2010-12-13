#include <IdentifiedEntityData.h>

IdentifiedEntityData::IdentifiedEntityData(const qulonglong& id) :
	EntityData(), _id(id) {
}

IdentifiedEntityData::IdentifiedEntityData(const IdentifiedEntityData& other) :
	EntityData(other), _id(other._id) {
}

IdentifiedEntityData::~IdentifiedEntityData() {
}
