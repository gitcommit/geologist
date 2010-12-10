#include <DataType.h>

#include <DbModel.h>

DataType::DataType(DbModel* m, const QString& name, const QString& sqlName) :
	InDbModelElement(m, name), _sqlName(sqlName) {
	m->registerDataType(this);
}

DataType::~DataType() {
}

QStringList DataType::create() const {
	QStringList ret;
	ret.append(QString("-- Data Type %1").arg(sqlName()));
	return ret;
}