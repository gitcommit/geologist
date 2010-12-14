#include <Lib/ORM/Private/StandardEntityData.h>

StandardEntityData::StandardEntityData(const qulonglong& id,
		const QString& name, const QString& code, const QString& description) :
	IdentifiedEntityData(id), _name(name), _code(code),
			_description(description) {
}

StandardEntityData::StandardEntityData(const StandardEntityData& other) :
	IdentifiedEntityData(other), _name(other._name), _code(other._code),
			_description(other._description) {
}

StandardEntityData::~StandardEntityData() {
}
