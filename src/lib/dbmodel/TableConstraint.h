#ifndef TABLECONSTRAINT_H_
#define TABLECONSTRAINT_H_

#include <InTableModelComponent.h>

class TableColumn;

class TableConstraint : public InTableModelComponent {
	Q_OBJECT
public:
	TableConstraint(Table* Table = 0, const QString& name = QString::null);
	TableConstraint(const TableConstraint& other);
	virtual ~TableConstraint();
	virtual void appendColumn(TableColumn* col) = 0;
};

#endif /*TABLECONSTRAINT_H_*/
