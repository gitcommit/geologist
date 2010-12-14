#ifndef FOREIGNKEYCONSTRAINTDATA_H_
#define FOREIGNKEYCONSTRAINTDATA_H_

#include <Lib/DBModel/Private/Base.h>

#include <Lib/DBModel/TableColumn.h>
#include <Lib/DBModel/TableColumnPair.h>

class ForeignKeyConstraintData : public Base {
public:
	ForeignKeyConstraintData(const QString& name = QString::null);
	ForeignKeyConstraintData(const ForeignKeyConstraintData& other);
	virtual ~ForeignKeyConstraintData();
	TableColumnPairList columnPairs() const;
	void appendColumnPair(TableColumn* left, TableColumn* right);
	void setReferencedTable(Table* t);
	Table* referencedTable() const;
private:
	TableColumnPairList _cols;
	Table* _referencedTable;
};

#endif /*FOREIGNKEYCONSTRAINTDATA_H_*/
