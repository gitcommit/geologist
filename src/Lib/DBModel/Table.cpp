#include <Lib/DBModel/Table.h>

#include <QtCore/QStringList>

#include <Lib/DBModel/Schema.h>
#include <Lib/DBModel/TableColumn.h>
#include <Lib/DBModel/PrimaryKeyConstraint.h>

Table::Table(Schema* schema, const QString& name) :
	InSchemaModelComponent(schema), _d(0) {
	_d = new TableData;
	setName(name);
}

Table::Table(const Table& other) :
	_d(other._d) {
}

Table::~Table() {
}

void Table::setName(const QString& n) {
	setObjectName(n);
	_d->setName(n);
}

QString Table::name() const {
	return _d->name();
}

QStringList Table::create() const {
	QStringList ret;
	ret.append(QString("CREATE Table %1();").arg(qualifiedName()));
	return ret;
}

QString Table::qualifiedName() const {
	return QString("%1.%2").arg(schema()->qualifiedName()).arg(name());
}

PrimaryKeyConstraint* Table::primaryKeyConstraint() const {
	return findChild<PrimaryKeyConstraint*>();
}

bool Table::hasPrimaryKeyConstraint() const {
	return (0 != primaryKeyConstraint());
}

TableColumn* Table::column(const QString& name) {
	if (!findChild<TableColumn*>(name)) {
		qFatal(tr("No Column %1 in Table %2").arg(name).arg(qualifiedName()).toLocal8Bit());
	}
	return findChild<TableColumn*>(name);
}

TableColumnList Table::columns() const {
	return findChildren<TableColumn*>();
}