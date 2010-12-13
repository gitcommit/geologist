#include <DbModel.h>

#include <QtCore/QStringList>
#include <QtCore/QDebug>

#include <Schema.h>
#include <Table.h>
#include <DataType.h>
#include <Sequence.h>
#include <TableColumn.h>
#include <PrimaryKeyConstraint.h>
#include <UniqueConstraint.h>
#include <CheckConstraint.h>
#include <ForeignKeyConstraint.h>

#include <XMLParser.h>

DbModel::DbModel(QObject* p, const QString& n) :
	ModelComponent(p), _d(0) {
	_d = new DbModelData;
	_parser = new XMLParser(this);
	connect(_parser, SIGNAL(createPrimaryKeyConstraint(const QString&, const QString&, const QString&, const QStringList&)), this, SLOT(createPrimaryKeyConstraint(const QString&, const QString&, const QString&, const QStringList&)));
	connect(_parser, SIGNAL(createUniqueConstraint(const QString&, const QString&, const QString&, const QStringList&)), this, SLOT(createUniqueConstraint(const QString&, const QString&, const QString&, const QStringList&)));
	connect(_parser, SIGNAL(createCheckConstraint(const QString&, const QString&, const QString&, const QStringList&, const QString&)), this, SLOT(createCheckConstraint(const QString&, const QString&, const QString&, const QStringList&, const QString&)));
	connect(_parser, SIGNAL(createForeignKeyConstraint(const QString&, const QString&, const QString&, const QStringList&, const QString&, const QString&, const QStringList&)), this, SLOT(createForeignKeyConstraint(const QString&, const QString&, const QString&, const QStringList&, const QString&, const QString&, const QStringList&)));
	connect(_parser, SIGNAL(createDataType(const QString&, const QString&, const bool&)), this, SLOT(createDataType(const QString&, const QString&, const bool&)));
	connect(_parser, SIGNAL(createSchema(const QString&)), this, SLOT(createSchema(const QString&)));
	connect(_parser, SIGNAL(createSequence(const QString&, const QString&)), this, SLOT(createSequence(const QString&, const QString&)));
	connect(_parser, SIGNAL(createTable(const QString&, const QString&)), this, SLOT(createTable(const QString&, const QString&)));
	connect(_parser, SIGNAL(createTableColumn(const QString&, const QString&, const QString&, const QString&, const bool&)), this, SLOT(createTableColumn(const QString&, const QString&, const QString&, const QString&, const bool&)));
	setName(n);
}

DbModel::DbModel(const DbModel& other) :
	_d(other._d) {

}

void DbModel::loadFromFile(const QString& fn) {
	_parser->loadFromFile(fn);
}

DbModel::~DbModel() {
}

QStringList DbModel::createDataTypes() const {
	QStringList ret;
	DataTypeList lst = findChildren<DataType*>();
	for (DataTypeList::const_iterator i = lst.begin(); i != lst.end(); i++) {
		ret.append((*i)->create());
	}
	return ret;
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
		ret.append(tr("-- %1 columns omitted.").arg((*i)->findChildren<TableColumn*>().size()));
	}
	return ret;
}

QStringList DbModel::createSequences() const {
	QStringList ret;
	SequenceList lst = findChildren<Sequence*>();
	for(SequenceList::const_iterator i = lst.begin(); i != lst.end(); i++) {
		ret.append((*i)->create());
	}
	return ret;
}

QStringList DbModel::createTableColumns() const {
	QStringList ret;
	TableColumnList lst = findChildren<TableColumn*>();
	for (TableColumnList::const_iterator i = lst.begin(); i != lst.end(); i++) {
		ret.append((*i)->create());
	}
	return ret;
}

QStringList DbModel::createPrimaryKeyConstraints() const {
	QStringList ret;
	PrimaryKeyConstraintList lst = findChildren<PrimaryKeyConstraint*>();
	for (PrimaryKeyConstraintList::const_iterator i = lst.begin(); i != lst.end(); i++) {
		ret.append((*i)->create());
	}
	return ret;
}

QStringList DbModel::createForeignKeyConstraints() const {
	QStringList ret;
	ForeignKeyConstraintList lst = findChildren<ForeignKeyConstraint*>();
	for (ForeignKeyConstraintList::const_iterator i = lst.begin(); i != lst.end(); i++) {
		ret.append((*i)->create());
	}
	return ret;
}

QStringList DbModel::createUniqueConstraints() const {
	QStringList ret;
	UniqueConstraintList lst = findChildren<UniqueConstraint*>();
	for (UniqueConstraintList::const_iterator i = lst.begin(); i != lst.end(); i++) {
		ret.append((*i)->create());
	}
	return ret;
}

QStringList DbModel::createCheckConstraints() const {
	QStringList ret;
	CheckConstraintList lst = findChildren<CheckConstraint*>();
	for (CheckConstraintList::const_iterator i = lst.begin(); i != lst.end(); i++) {
		ret.append((*i)->create());
	}
	return ret;
}

QStringList DbModel::create() const {
	QStringList ret;
	ret.append(QString("-- CREATE DATABASE %1").arg(name()));
	ret.append(createDataTypes());
	ret.append(createSchemas());
	ret.append(createSequences());
	ret.append(createTables());
	ret.append(createTableColumns());
	ret.append(createPrimaryKeyConstraints());
	ret.append(createUniqueConstraints());
	ret.append(createCheckConstraints());
	ret.append(createForeignKeyConstraints());
	return ret;
}

void DbModel::setName(const QString& n) {
	setObjectName(n);
	_d->setName(n);
}

QString DbModel::name() const {
	return _d->name();
}

QString DbModel::qualifiedName() const {
	return name();
}

Schema* DbModel::schema(const QString& name) const {
	return findChild<Schema*>(name);
}

DataType* DbModel::dataType(const QString& name) const {
	return findChild<DataType*>(name);
}

void DbModel::createSchema(const QString& name) {
	(void) new Schema(this, name);
}

void DbModel::createSequence(const QString& schemaName, const QString& sequenceName) {
	(void) new Sequence(schema(schemaName), sequenceName);
}

void DbModel::createTable(const QString& schemaName, const QString& tableName) {
	(void) new Table(schema(schemaName), tableName);
}

void DbModel::createTableColumn(const QString& schemaName, const QString& tableName, const QString& colName, const QString& typeName, const bool& nullable) {
	(void) new TableColumn(schema(schemaName)->table(tableName), colName, dataType(typeName), nullable);
}

void DbModel::createDataType(const QString& name, const QString& sqlName, const bool& requiresQuoting) {
	(void) new DataType(this, name, sqlName, requiresQuoting);
}

void DbModel::createPrimaryKeyConstraint(const QString& schemaName, const QString& tableName, const QString& name, const QStringList& columnNames) {
	TableConstraint* c = new PrimaryKeyConstraint(schema(schemaName)->table(tableName), name);
	for (QStringList::const_iterator i = columnNames.begin(); i != columnNames.end(); i++) {
		c->appendColumn(schema(schemaName)->table(tableName)->column(*i));
	}
}

void DbModel::createUniqueConstraint(const QString& schemaName, const QString& tableName, const QString& name, const QStringList& columnNames) {
	TableConstraint* c = new UniqueConstraint(schema(schemaName)->table(tableName), name);
	for (QStringList::const_iterator i = columnNames.begin(); i != columnNames.end(); i++) {
		c->appendColumn(schema(schemaName)->table(tableName)->column(*i));
	}
}

void DbModel::createCheckConstraint(const QString& schemaName, const QString& tableName, const QString& name, const QStringList& columnNames, const QString& definition) {
	TableConstraint* c = new CheckConstraint(schema(schemaName)->table(tableName), name, definition);
	for (QStringList::const_iterator i = columnNames.begin(); i != columnNames.end(); i++) {
		c->appendColumn(schema(schemaName)->table(tableName)->column(*i));
	}
}

void DbModel::createForeignKeyConstraint(const QString& name, const QString& schemaName, const QString& tableName, const QStringList& columnNames, const QString& referencedSchemaName, const QString& referencedTableName, const QStringList& referencedColumnNames) {
	Table* local = schema(schemaName)->table(tableName);
	Table* referenced = schema(referencedSchemaName)->table(referencedTableName);
	Q_CHECK_PTR(local);
	Q_CHECK_PTR(referenced);
	ForeignKeyConstraint* c = new ForeignKeyConstraint(name, local, referenced);
	for (int i = 0; i != columnNames.size(); i++) {
		c->appendColumnPair(local->column(columnNames.at(i)), referenced->column(referencedColumnNames.at(i)));
	}
}
