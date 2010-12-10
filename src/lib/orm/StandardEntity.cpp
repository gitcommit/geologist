#include <StandardEntity.h>

StandardEntity::StandardEntity(QObject* p, const qulonglong& id,
		const QString& name, const QString& code, const QString& description) :
	IdentifiedEntity(p, id) {
}

StandardEntity::~StandardEntity() {
}
