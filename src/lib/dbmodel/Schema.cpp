#include <Schema.h>

#include <DbModel.h>
#include <Sequence.h>

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

Sequence* Schema::createSequence(const QString& name) {
	return registerSequence(new Sequence(this, name));
}
	
Sequence* Schema::registerSequence(Sequence* s) {
	if (!_sequences.contains(s->name())) {
		_sequences.insert(s->name(), s);
	}
	return s;
}
	
Sequence* Schema::sequence(const QString& name) {
	Q_ASSERT(_sequences.contains(name));
	return _sequences.value(name);
}
