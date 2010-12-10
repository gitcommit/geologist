#include <Schema.h>

#include <DbModel.h>
#include <Sequence.h>
#include <Table.h>

Schema::Schema(DbModel* m, const QString& name) :
	InDbModelElement(m, name) {
	m->registerSchema(this);
}

Schema::~Schema() {
}

QStringList Schema::create() const {
	QStringList ret;
	ret.append(QString("CREATE SCHEMA %1;").arg(name()));
	return ret;
}
	
Sequence* Schema::registerSequence(Sequence* s) {
	Q_ASSERT(0 != s);
	if (!_sequences.contains(s->name())) {
		_sequences.insert(s->name(), s);
	}
	return s;
}
	
Sequence* Schema::sequence(const QString& name) {
	Q_ASSERT(_sequences.contains(name));
	return _sequences.value(name);
}

Table* Schema::registerTable(Table* t) {
	Q_ASSERT(0 != t);
	if (!_tables.contains(t->name())) {
		_tables.insert(t->name(), t);
	}
	return t;
}

Table* Schema::table(const QString& name) {
	Q_ASSERT(_tables.contains(name));
	return _tables.value(name);
}