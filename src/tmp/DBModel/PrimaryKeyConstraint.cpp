#include <PrimaryKeyConstraint.h>

#include <QtCore/QStringList>

#include <Table.h>

PrimaryKeyConstraint::PrimaryKeyConstraint(Table* table, const QString& name) :
	TableConstraint(table), _d(0) {
	_d = new PrimaryKeyConstraintData;
	setName(name);
}

PrimaryKeyConstraint::PrimaryKeyConstraint(const PrimaryKeyConstraint& other) :
	_d(other._d) {
}

PrimaryKeyConstraint::~PrimaryKeyConstraint() {
}

void PrimaryKeyConstraint::setName(const QString& n) {
	setObjectName(n);
	_d->setName(n);
}

QString PrimaryKeyConstraint::name() const {
	return _d->name();
}

QStringList PrimaryKeyConstraint::create() const {
	QStringList ret;
	ret.append(QString("ALTER TABLE %1 ADD CONSTRAINT %2 PRIMARY KEY(%3);")
			.arg(table()->qualifiedName())
			.arg(name())
			.arg(columnNames().join(", ")));
	return ret;
}

QString PrimaryKeyConstraint::qualifiedName() const {
	return name();
}

QStringList PrimaryKeyConstraint::columnNames() const {
	return _d->columnNames();
}


void PrimaryKeyConstraint::appendColumn(TableColumn* col) {
	_d->appendColumn(col);
}