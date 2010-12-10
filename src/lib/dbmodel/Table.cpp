#include <Table.h>

#include <QtCore/QStringList>

#include <Schema.h>

Table::Table(Schema* schema, const QString& name) :
	QObject(schema), _d(0) {
	_d = new TableData;
	setName(name);
}

Table::Table(const Table& other) :
	_d(other._d) {
}

Table::~Table() {
}

void Table::setName(const QString& n) {
	_d->setName(n);
}

QString Table::name() const {
	return _d->name();
}

QStringList Table::create() const {
	QStringList ret;
	ret.append(QString("CREATE Table %1();").arg(name()));
	return ret;
}