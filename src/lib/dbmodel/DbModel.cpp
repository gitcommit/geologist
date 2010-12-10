#include <DbModel.h>

#include <QDebug>

#include <DataType.h>
#include <Schema.h>
#include <Sequence.h>
#include <Table.h>

DbModel::DbModel(QObject* p, const QString& name) {
}

DbModel::~DbModel() {
}

Schema* DbModel::registerSchema(Schema* schema) {
	Q_ASSERT(0 != schema);
	if (!_schemas.contains(schema->name())) {
		_schemas.insert(schema->name(), schema);
	}
	return schema;
}

Schema* DbModel::schema(const QString& name) {
	Q_ASSERT(_schemas.contains(name));
	return _schemas.value(name);
}

DataType* DbModel::registerDataType(DataType* t) {
	Q_ASSERT(0 != t);
	if (!_dataTypes.contains(t->name())) {
		_dataTypes.insert(t->name(), t);
	}
	return t;
}

DataType* DbModel::dataType(const QString& name) {
	Q_ASSERT(_dataTypes.contains(name));
	return _dataTypes.value(name);
}

QStringList DbModel::createDataTypes() const {
	QStringList ret;
	QMap<QString, DataType*>::const_iterator i = _dataTypes.constBegin();
	while (i != _dataTypes.constEnd()) {
		DataType* t = i.value();
		Q_ASSERT(0 != t);
		ret.append(t->create());
		++i;
	}
	return ret;
}

QStringList DbModel::createSchemas() const {
	QStringList ret;
	QMap<QString, Schema*>::const_iterator i = _schemas.constBegin();
	while (i != _schemas.constEnd()) {
		Schema* schema = i.value();
		Q_ASSERT(0 != schema);
		ret.append(schema->create());
		ret.append(createSequences(schema));
		ret.append(createTables(schema));
		++i;
	}
	return ret;
}

QStringList DbModel::createSequences(Schema* s) const {
	Q_ASSERT(0 != s);
	QStringList ret;
	QMap<QString, Sequence*> sequences = s->sequences();
	QMap<QString, Sequence*>::const_iterator i = sequences.constBegin();
	while(i != sequences.constEnd()) {
		Sequence* seq = i.value();
		Q_ASSERT(0 != seq);
		ret.append(seq->create());
		i++;
	}
	return ret;
}

QStringList DbModel::createTables(Schema* s) const {
	Q_ASSERT(0 != s);
	QStringList ret;
	QMap<QString, Table*> tables = s->tables();
	QMap<QString, Table*>::const_iterator i = tables.constBegin();
	while(i != tables.constEnd()) {
		Table* t = i.value();
		Q_ASSERT(0 != t);
		ret.append(t->create());
		i++;
	}
}

QStringList DbModel::create() const {
	QStringList ret;
	ret.append(createDataTypes());
	ret.append(createSchemas());
	return ret;
}