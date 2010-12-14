#include <Lib/DBModel/Sequence.h>

#include <QtCore/QStringList>

#include <Lib/DBModel/Schema.h>

Sequence::Sequence(Schema* schema, const QString& name) :
	InSchemaModelComponent(schema), _d(0) {
	_d = new SequenceData;
	setName(name);
}

Sequence::Sequence(const Sequence& other) :
	_d(other._d) {
}

Sequence::~Sequence() {
}

void Sequence::setName(const QString& n) {
	setObjectName(n);
	_d->setName(n);
}

QString Sequence::name() const {
	return _d->name();
}

QStringList Sequence::create() const {
	QStringList ret;
	ret.append(QString("CREATE SEQUENCE %1;").arg(qualifiedName()));
	return ret;
}

QString Sequence::qualifiedName() const {
	return QString("%1.%2").arg(schema()->qualifiedName()).arg(name());
}