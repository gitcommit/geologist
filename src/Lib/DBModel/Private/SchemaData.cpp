#include <Lib/DBModel/Private/SchemaData.h>

SchemaData::SchemaData(const QString& name) :
	Base(name) {
}

SchemaData::SchemaData(const SchemaData& other) :
	Base(other) {
}

SchemaData::~SchemaData() {
}
