#include <DbModel.h>

#include <QtCore/QStringList>

#include <Schema.h>
#include <Table.h>

DbModel::DbModel(QObject* p, const QString& n) :
	ModelComponent(p), _d(0) {
	_d = new DbModelData;
	setName(n);
}

DbModel::DbModel(const DbModel& other) :
	_d(other._d) {

}

DbModel::~DbModel() {
}

QStringList DbModel::createSchemas() const {
	QStringList ret;
	SchemaList lst = findChildren<Schema*>();
	for(SchemaList::const_iterator i = lst.begin(); i != lst.end(); i++) {
		ret.append((*i)->create());
	}
	return ret;
}

QStringList DbModel::createTables() const {
	QStringList ret;
	TableList lst = findChildren<Table*>();
	for(TableList::const_iterator i = lst.begin(); i != lst.end(); i++) {
		ret.append((*i)->create());
	}
	return ret;
}

QStringList DbModel::create() const {
	QStringList ret;
	ret.append(QString("-- CREATE DATABASE %1").arg(name()));
	ret.append(createSchemas());
	ret.append(createTables());
	return ret;
}

void DbModel::setName(const QString& n) {
	_d->setName(n);
}

QString DbModel::name() const {
	return _d->name();
}