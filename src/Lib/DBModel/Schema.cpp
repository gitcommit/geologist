#include <Lib/DBModel/Schema.h>

#include <QtCore/QStringList>

#include <Lib/DBModel/DBModel.h>
#include <Lib/DBModel/Table.h>

Schema::Schema(DBModel* dbM, const QString& name) :
	InDBModelComponent(dbM), _d(0) {
	_d = new SchemaData;
	setName(name);
}

Schema::Schema(const Schema& other) :
	_d(other._d) {
}

Schema::~Schema() {
}

void Schema::setName(const QString& n) {
	setObjectName(n);
	_d->setName(n);
}

QString Schema::name() const {
	return _d->name();
}

QStringList Schema::create() const {
	QStringList ret;
	ret.append(QString("CREATE SCHEMA %1;").arg(name()));
	return ret;
}

QString Schema::qualifiedName() const {
	return name();
}

Table* Schema::table(const QString& name) const {
	return findChild<Table*>(name);
}
