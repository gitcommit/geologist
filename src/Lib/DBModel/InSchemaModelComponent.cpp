#include <InSchemaModelComponent.h>

#include <Schema.h>

InSchemaModelComponent::InSchemaModelComponent(Schema* schema) :
	ModelComponent(schema) {
}

InSchemaModelComponent::~InSchemaModelComponent() {
}

Schema* InSchemaModelComponent::schema() const {
	return qobject_cast<Schema*>(parent());
}
