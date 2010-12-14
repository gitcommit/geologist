#include <Lib/DBModel/UniqueConstraint.h>

#include <QtCore/QStringList>

#include <Lib/DBModel/Table.h>

UniqueConstraint::UniqueConstraint(Table* table, const QString& name) :
	TableConstraint(table), _d(0) {
	_d = new UniqueConstraintData;
	setName(name);
}

UniqueConstraint::UniqueConstraint(const UniqueConstraint& other) :
	_d(other._d) {
}

UniqueConstraint::~UniqueConstraint() {
}

void UniqueConstraint::setName(const QString& n) {
	setObjectName(n);
	_d->setName(n);
}

QString UniqueConstraint::name() const {
	return _d->name();
}

QStringList UniqueConstraint::create() const {
	QStringList ret;
	ret.append(QString("ALTER TABLE %1 ADD CONSTRAINT %2 UNIQUE(%3);")
			.arg(table()->qualifiedName())
			.arg(name())
			.arg(columnNames().join(", ")));
	return ret;
}

QString UniqueConstraint::qualifiedName() const {
	return name();
}

QStringList UniqueConstraint::columnNames() const {
	return _d->columnNames();
}


void UniqueConstraint::appendColumn(TableColumn* col) {
	_d->appendColumn(col);
}