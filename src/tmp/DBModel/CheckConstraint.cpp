#include <CheckConstraint.h>

#include <QtCore/QStringList>

#include <Table.h>

CheckConstraint::CheckConstraint(Table* table, const QString& name, const QString& definition) :
	TableConstraint(table), _d(0) {
	_d = new CheckConstraintData;
	setName(name);
	setDefinition(definition);
}

CheckConstraint::CheckConstraint(const CheckConstraint& other) :
	_d(other._d) {
}

CheckConstraint::~CheckConstraint() {
}

void CheckConstraint::setName(const QString& n) {
	setObjectName(n);
	_d->setName(n);
}

void CheckConstraint::setDefinition(const QString& v) {
	_d->setDefinition(v);
}

QString CheckConstraint::name() const {
	return _d->name();
}

QString CheckConstraint::definition() const  {
	return _d->definition();
}

QStringList CheckConstraint::create() const {
	QStringList ret;
	QStringList checks;
	QStringList cols = columnNames();
	for (QStringList::const_iterator i = cols.begin(); i != cols.end(); i++) {
		checks.append(QString("%1 %2").arg((*i), definition()));
	}
	ret.append(QString("ALTER TABLE %1 ADD CONSTRAINT %2 CHECK (%3);")
			.arg(table()->qualifiedName())
			.arg(name())
			.arg(checks.join(" AND ")));
	return ret;
}

QString CheckConstraint::qualifiedName() const {
	return name();
}

QStringList CheckConstraint::columnNames() const {
	return _d->columnNames();
}


void CheckConstraint::appendColumn(TableColumn* col) {
	_d->appendColumn(col);
}