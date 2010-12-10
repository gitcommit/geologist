#include "InSchemaModelElement.h"

#include <Schema.h>

InSchemaModelElement::InSchemaModelElement(Schema* s, const QString& n) :
	DbModelElement(s, n) {
}

InSchemaModelElement::~InSchemaModelElement() {
}

QString InSchemaModelElement::qualifiedName() const {
	return QString("%1.%2").arg(schema()->name()).arg(name());
}

Schema* InSchemaModelElement::schema() const {
	Q_ASSERT(0 != parent());
	return qobject_cast<Schema*>(parent());
}