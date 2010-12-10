#include <DataType.h>

#include <QtCore/QStringList>
#include <DbModel.h>

DataType::DataType(DbModel* dbM, const QString& name, const QString& sqlName) :
	InDbModelComponent(dbM), _d(0) {
	_d = new DataTypeData;
	setName(name);
	setSqlName(sqlName);
}

DataType::DataType(const DataType& other) :
	_d(other._d) {
}

DataType::~DataType() {
}

void DataType::setName(const QString& n) {
	_d->setName(n);
}

void DataType::setSqlName(const QString& n) {
	_d->setSqlName(n);
}

QString DataType::name() const {
	return _d->name();
}

QString DataType::sqlName() const {
	return _d->sqlName();
}

QStringList DataType::create() const {
	QStringList ret;
	ret.append(QString("-- SQL Data Type: %1;").arg(qualifiedName()));
	return ret;
}

QString DataType::qualifiedName() const {
	return sqlName();
}
