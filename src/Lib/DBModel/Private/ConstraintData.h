#ifndef CONSTRAINTDATA_H_
#define CONSTRAINTDATA_H_

#include <Lib/DBModel/Private/Base.h>

#include <Lib/DBModel/TableColumn.h>

class ConstraintData : public Base {
public:
	ConstraintData(const QString& name = QString::null);
	ConstraintData(const ConstraintData& other);
	virtual ~ConstraintData();
	QStringList columnNames() const;
	void appendColumn(TableColumn* col);
private:
	TableColumnList _cols;
};

#endif /*CONSTRAINTDATA_H_*/
