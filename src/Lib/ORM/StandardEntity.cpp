#include <Lib/ORM/StandardEntity.h>

#include <Lib/ORM/Private/StandardEntityData.h>

StandardEntity::StandardEntity(QObject* p, const qulonglong& id,
		const QString& name, const QString& code, const QString& description) :
	IdentifiedEntity(p, id) {
	connect(this, SIGNAL(nameChanged(const QString&)), this, SIGNAL(dataChanged()));
	connect(this, SIGNAL(codeChanged(const QString&)), this, SIGNAL(dataChanged()));
	connect(this, SIGNAL(descriptionChanged(const QString&)), this, SIGNAL(dataChanged()));
}

StandardEntity::StandardEntity(const StandardEntity& other) :
	IdentifiedEntity(other) {
}

StandardEntity::~StandardEntity() {
}
