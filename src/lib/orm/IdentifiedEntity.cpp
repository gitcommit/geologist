#include "IdentifiedEntity.h"

IdentifiedEntity::IdentifiedEntity(QObject* p, const qulonglong& id) :
	Entity(p), id_(id) {
}

IdentifiedEntity::~IdentifiedEntity() {
}
