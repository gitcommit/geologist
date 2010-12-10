#include <DbModel.h>

#include <QtCore/QStringList>

DbModel::DbModel(const QString& n) :
	d(0) {
	d = new DbModelData;
	setName(n);
}

DbModel::DbModel(const DbModel& other) :
	d(other.d) {

}

DbModel::~DbModel() {
}

QStringList DbModel::create() const {
	QStringList ret;
	ret.append(QString("-- CREATE DATABASE %1").arg(name()));
	return ret;
}

void DbModel::setName(const QString& n) {
	d->setName(n);
}

QString DbModel::name() const {
	return d->name();
}