#include <Lib/DBModel/ForeignKeyConstraint.h>

#include <QtCore/QStringList>

#include <Lib/DBModel/Table.h>

ForeignKeyConstraint::ForeignKeyConstraint(const QString& name, Table* localTable, Table* referencedTable) :
	TableConstraint(localTable), _d(0) {
	_d = new ForeignKeyConstraintData;
	setName(name);
	setReferencedTable(referencedTable);
}

ForeignKeyConstraint::ForeignKeyConstraint(const ForeignKeyConstraint& other) :
	_d(other._d) {
}

ForeignKeyConstraint::~ForeignKeyConstraint() {
}

void ForeignKeyConstraint::setName(const QString& n) {
	setObjectName(n);
	_d->setName(n);
}

QString ForeignKeyConstraint::name() const {
	return _d->name();
}

QStringList ForeignKeyConstraint::create() const {
	QStringList ret;
	QStringList local;
	QStringList referenced;
	
	TableColumnPairList pairs = columnPairs();
	for (TableColumnPairList::const_iterator i = pairs.begin(); i != pairs.end(); i++) {
		TableColumn* left = (*i)->left();
		TableColumn* right = (*i)->right();
		Q_ASSERT(0 != left);
		Q_ASSERT(0 != right);
		local.append((*i)->left()->name());
		referenced.append((*i)->right()->name());
	}
	
	ret.append(QString("ALTER TABLE %1 ADD CONSTRAINT %2 FOREIGN KEY (%3) REFERENCES %4 (%5);")
			.arg(table()->qualifiedName())
			.arg(name())
			.arg(local.join(", "))
			.arg(referencedTable()->qualifiedName())
			.arg(referenced.join(", ")));
	return ret;
}

QString ForeignKeyConstraint::qualifiedName() const {
	return name();
}

TableColumnPairList ForeignKeyConstraint::columnPairs() const {
	return _d->columnPairs();
}

void ForeignKeyConstraint::appendColumnPair(TableColumn* left, TableColumn* right) {
	_d->appendColumnPair(left, right);
}

void ForeignKeyConstraint::setReferencedTable(Table* t) {
	_d->setReferencedTable(t);
}

Table* ForeignKeyConstraint::referencedTable() const {
	return _d->referencedTable();
}

Table* ForeignKeyConstraint::localTable() const {
	return qobject_cast<Table*>(parent());
}
