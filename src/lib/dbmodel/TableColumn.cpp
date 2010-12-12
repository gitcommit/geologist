#include <TableColumn.h>

#include <QtCore/QStringList>

#include <Table.h>
#include <DataType.h>

TableColumn::TableColumn(Table* table, const QString& name, DataType* dataType) :
	InTableModelComponent(table), _d(0) {
	_d = new TableColumnData;
	setName(name);
	setDataType(dataType);
}

TableColumn::TableColumn(const TableColumn& other) :
	_d(other._d) {
}

TableColumn::~TableColumn() {
}

void TableColumn::setName(const QString& n) {
	setObjectName(n);
	_d->setName(n);
}

void TableColumn::setDataType(DataType* t) {
	_d->setDataType(t);
}

QString TableColumn::name() const {
	return _d->name();
}

DataType* TableColumn::dataType() const {
	return _d->dataType();
}

QStringList TableColumn::create() const {
	QStringList ret;
	ret.append(QString("ALTER TABLE %1 ADD COLUMN %2 %3;")
			.arg(table()->qualifiedName())
			.arg(name())
			.arg(dataType()->sqlName()));
	return ret;
}

QString TableColumn::qualifiedName() const {
	return QString("%1.%2").arg(table()->qualifiedName()).arg(name());
}