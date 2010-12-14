#include <Lib/DBModel/Private/ForeignKeyConstraintData.h>

#include <QtCore/QStringList>

ForeignKeyConstraintData::ForeignKeyConstraintData(const QString& name) :
	Base(name), _referencedTable(0) {
}

ForeignKeyConstraintData::ForeignKeyConstraintData(const ForeignKeyConstraintData& other) :
	Base(other), _cols(other._cols), _referencedTable(other._referencedTable) {
}

ForeignKeyConstraintData::~ForeignKeyConstraintData() {
}

TableColumnPairList ForeignKeyConstraintData::columnPairs() const {
	return _cols;
}

void ForeignKeyConstraintData::appendColumnPair(TableColumn* l, TableColumn* r) {
	_cols.append(new TableColumnPair(l, r));
}

void ForeignKeyConstraintData::setReferencedTable(Table* t) {
	_referencedTable = t;
}

Table* ForeignKeyConstraintData::referencedTable() const {
	return _referencedTable;
}
