#include "IdentifiedEntity.h"

IdentifiedEntity::IdentifiedEntity(QObject* p, const qulonglong& id) :
	Entity(p), _id(id) {
	connect(this, SIGNAL(idChanged()), this, SIGNAL(dataChanged()));
}

IdentifiedEntity::~IdentifiedEntity() {
}
