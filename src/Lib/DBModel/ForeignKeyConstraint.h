#ifndef FOREIGNKEYCONSTRAINT_H_
#define FOREIGNKEYCONSTRAINT_H_

#include <Lib/DBModel/TableConstraint.h>

#include <Lib/DBModel/Private/ForeignKeyConstraintData.h>

class ForeignKeyConstraint : public TableConstraint {
	Q_OBJECT
public:
	ForeignKeyConstraint(const QString& name = QString::null, Table* table = 0, Table* referencedTable = 0);
	ForeignKeyConstraint(const ForeignKeyConstraint& other);
	virtual ~ForeignKeyConstraint();

	void setName(const QString& n);
	QString name() const;
	virtual QString qualifiedName() const;
	QStringList create() const;
	TableColumnPairList columnPairs() const;
	void appendColumnPair(TableColumn* left, TableColumn* right);
	void setReferencedTable(Table* t);
	Table* referencedTable() const;
	Table* localTable() const;
private:
	virtual void appendColumn(TableColumn*) {}
	QExplicitlySharedDataPointer<ForeignKeyConstraintData> _d;
};

typedef QList<ForeignKeyConstraint*> ForeignKeyConstraintList;


#endif /*FOREIGNKEYCONSTRAINT_H_*/
