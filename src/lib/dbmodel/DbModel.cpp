#include <DbModel.h>

#include <QDebug>

#include <DataType.h>
#include <Schema.h>
#include <Sequence.h>

DbModel::DbModel(QObject* p, const QString& name) {
}

DbModel::~DbModel() {
}

Schema* DbModel::createSchema(const QString& name) {
	return registerSchema(new Schema(this, name));
}

Schema* DbModel::registerSchema(Schema* schema) {
	if (!_schemas.contains(schema->name())) {
		_schemas.insert(schema->name(), schema);
	}
	return schema;
}

Schema* DbModel::schema(const QString& name) {
	Q_ASSERT(_schemas.contains(name));
	return _schemas.value(name);
}

DataType* DbModel::createDataType(const QString& name, const QString& sqlName) {
	return registerDataType(new DataType(this, name, sqlName));
}

DataType* DbModel::registerDataType(DataType* t) {
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
		ret.append(i.value()->create());
		++i;
	}
	return ret;
}

QStringList DbModel::createSchemas() const {
	QStringList ret;
	QMap<QString, Schema*>::const_iterator i = _schemas.constBegin();
	while (i != _schemas.constEnd()) {
		ret.append(i.value()->create());
		ret.append(createSequences(i.value()));
		++i;
	}
	return ret;
}

QStringList DbModel::createSequences(Schema* s) const {
	QStringList ret;
	QMap<QString, Sequence*> sequences = s->sequences();
	QMap<QString, Sequence*>::const_iterator i = sequences.constBegin();
	while(i != sequences.constEnd()) {
		ret.append(i.value()->create());
		i++;
	}
	return ret;
}

QStringList DbModel::create() const {
	QStringList ret;
	ret.append(createDataTypes());
	ret.append(createSchemas());
	return ret;
}