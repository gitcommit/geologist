#include <Lib/ORM/IdentifiedEntity.h>

#include <Lib/ORM/IdentifiedEntityData.h>

IdentifiedEntity::IdentifiedEntity(QObject* p, const qulonglong& id) :
	Entity(p) {
	setData(new IdentifiedEntityData(id));
	connect(this, SIGNAL(idChanged(const qulonglong&)), this, SIGNAL(dataChanged()));
}

IdentifiedEntity::IdentifiedEntity(const IdentifiedEntity& other) :
	Entity(other) {
}

IdentifiedEntity::~IdentifiedEntity() {
}

IdentifiedEntityData* IdentifiedEntity::identifiedEntityData() const {
	Q_ASSERT(hasData());
	Q_CHECK_PTR(data());
	return reinterpret_cast<IdentifiedEntityData*>(_d);
}

void IdentifiedEntity::setId(const qulonglong& id) {
	Q_ASSERT(hasData());
	emit idChanged(id);
	identifiedEntityData()->setId(id);
}

qulonglong IdentifiedEntity::id() const {
	Q_ASSERT(hasData());
	Q_CHECK_PTR(identifiedEntityData());
	return identifiedEntityData()->id();
}

bool IdentifiedEntity::hasId() const {
	Q_ASSERT(hasData());
	Q_CHECK_PTR(identifiedEntityData());
	return identifiedEntityData()->hasId();
}
