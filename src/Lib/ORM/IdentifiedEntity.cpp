#include <Lib/ORM/IdentifiedEntity.h>

#include <Lib/ORM/Private/IdentifiedEntityData.h>

IdentifiedEntity::IdentifiedEntity(QObject* p, const qulonglong& id) :
	Entity(p) {
	connect(this, SIGNAL(idChanged(const qulonglong&)), this, SIGNAL(dataChanged()));
}

IdentifiedEntity::IdentifiedEntity(const IdentifiedEntity& other) :
	Entity(other) {
}

IdentifiedEntity::~IdentifiedEntity() {
}
