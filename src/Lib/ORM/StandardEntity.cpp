#include <StandardEntity.h>

#include <StandardEntityData.h>

StandardEntity::StandardEntity(QObject* p, const qulonglong& id,
		const QString& name, const QString& code, const QString& description) :
	IdentifiedEntity(p, id) {
	setData(new StandardEntityData(id, name, code, description));
	connect(this, SIGNAL(nameChanged(const QString&)), this, SIGNAL(dataChanged()));
	connect(this, SIGNAL(codeChanged(const QString&)), this, SIGNAL(dataChanged()));
	connect(this, SIGNAL(descriptionChanged(const QString&)), this, SIGNAL(dataChanged()));
}

StandardEntity::StandardEntity(const StandardEntity& other) :
	IdentifiedEntity(other) {
}

StandardEntity::~StandardEntity() {
}

StandardEntityData* StandardEntity::standardEntityData() const {
	Q_ASSERT(hasData());
	Q_CHECK_PTR(data());
	return reinterpret_cast<StandardEntityData*>(data());
}

void StandardEntity::setName(const QString& n) {
	emit nameChanged(n);
	standardEntityData()->setName(n);
}

void StandardEntity::setCode(const QString& c) {
	emit codeChanged(c);
	standardEntityData()->setCode(c);
}

void StandardEntity::setDescription(const QString& d) {
	emit descriptionChanged(d);
	standardEntityData()->setDescription(d);
}
QString StandardEntity::name() const {
	return standardEntityData()->name();
}

QString StandardEntity::code() const {
	return standardEntityData()->code();
}

QString StandardEntity::description() const {
	return standardEntityData()->description();
}
