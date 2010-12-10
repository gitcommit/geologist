#include <Schema.h>

#include <QtCore/QStringList>
#include <DbModel.h>

Schema::Schema(DbModel* dbM, const QString& name) :
	QObject(dbM), _d(0) {
	_d = new SchemaData;
	setName(name);
}

Schema::Schema(const Schema& other) :
	_d(other._d) {
}

Schema::~Schema() {
}

void Schema::setName(const QString& n) {
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