#include <Lib/DBModel/private/SchemaData.h>

SchemaData::SchemaData(const QString& name) :
	Base(name) {
}

SchemaData::SchemaData(const SchemaData& other) :
	Base(other) {
}

SchemaData::~SchemaData() {
}
