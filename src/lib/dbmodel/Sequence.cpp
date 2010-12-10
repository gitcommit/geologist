#include "Sequence.h"

#include <Schema.h>

Sequence::Sequence(Schema* s, const QString& n) :
	InSchemaModelElement(s, n) {
	s->registerSequence(this);
}

Sequence::~Sequence() {
}

QStringList Sequence::create() const {
	QStringList ret;
	ret.append(QString("CREATE SEQUENCE %1;").arg(qualifiedName()));
	return ret;
}