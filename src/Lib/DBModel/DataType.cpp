#include <Lib/DBModel/DataType.h>

#include <QtCore/QStringList>
#include <Lib/DBModel/DbModel.h>

DataType::DataType(DbModel* dbM, const QString& name, const QString& sqlName, const bool& requiresQuoting) :
	InDbModelComponent(dbM), _d(0) {
	_d = new DataTypeData;
	setName(name);
	setSqlName(sqlName);
	setRequiresQuoting(requiresQuoting);
}

DataType::DataType(const DataType& other) :
	_d(other._d) {
}

DataType::~DataType() {
}

void DataType::setName(const QString& n) {
	setObjectName(n);
	_d->setName(n);
}

void DataType::setRequiresQuoting(const bool& b) {
	_d->setRequiresQuoting(b);
}

void DataType::setSqlName(const QString& n) {
	_d->setSqlName(n);
}

QString DataType::name() const {
	return _d->name();
}

QString DataType::sqlName() const {
	Q_CHECK_PTR(_d);
	return _d->sqlName();
}

bool DataType::requiresQuoting() const {
	return _d->requiresQuoting();
}

QStringList DataType::create() const {
	QStringList ret;
	ret.append(QString("-- Data Type: %1 is database type %2;").arg(name()).arg(sqlName()));
	return ret;
}

QString DataType::qualifiedName() const {
	return sqlName();
}
