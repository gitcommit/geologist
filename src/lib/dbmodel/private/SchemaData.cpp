#include <private/SchemaData.h>

SchemaData::SchemaData(const QString& name) :
	_name(name) {
}

SchemaData::SchemaData(const SchemaData& other) :
	QSharedData(other), _name(other._name) {
}

SchemaData::~SchemaData() {
}
