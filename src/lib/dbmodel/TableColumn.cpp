#include <TableColumn.h>

#include <QtCore/QStringList>

#include <Table.h>
#include <DataType.h>

TableColumn::TableColumn(Table* table, const QString& name, DataType* dataType, const bool& nullable) :
	InTableModelComponent(table), _d(0) {
	_d = new TableColumnData;
	setName(name);
	setDataType(dataType);
	setNullable(nullable);
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

void TableColumn::setNullable(const bool& b) {
	_d->setNullable(b);
}

bool TableColumn::nullable() const {
	return _d->nullable();
}

QStringList TableColumn::create() const {
	QStringList ret;
	ret.append(QString("ALTER TABLE %1 ADD COLUMN %2 %3;")
			.arg(table()->qualifiedName())
			.arg(name())
			.arg(dataType()->sqlName()));
	if (!nullable()) {
		ret.append(QString("ALTER TABLE %1 ALTER COLUMN %2 SET NOT NULL;").arg(table()->qualifiedName()).arg(name()));
	} else {
		ret.append(QString("ALTER TABLE %1 ALTER COLUMN %2 DROP NOT NULL;").arg(table()->qualifiedName()).arg(name()));
	}
	return ret;
}

QString TableColumn::qualifiedName() const {
	return QString("%1.%2").arg(table()->qualifiedName()).arg(name());
}