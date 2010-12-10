#include <StandardEntity.h>

StandardEntity::StandardEntity(QObject* p, const qulonglong& id,
		const QString& name, const QString& code, const QString& description) :
	IdentifiedEntity(p, id) {
	connect(this, SIGNAL(nameChanged()), this, SIGNAL(dataChanged()));
	connect(this, SIGNAL(codeChanged()), this, SIGNAL(dataChanged()));
	connect(this, SIGNAL(descriptionChanged()), this, SIGNAL(dataChanged()));
}

StandardEntity::~StandardEntity() {
}
