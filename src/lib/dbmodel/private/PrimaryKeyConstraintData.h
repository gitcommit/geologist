#ifndef PRIMARYKEYCONSTRAINTDATA_H_
#define PRIMARYKEYCONSTRAINTDATA_H_

#include <private/Base.h>

#include <TableColumn.h>

class PrimaryKeyConstraintData : public Base {
public:
	PrimaryKeyConstraintData(const QString& name = QString::null);
	PrimaryKeyConstraintData(const PrimaryKeyConstraintData& other);
	virtual ~PrimaryKeyConstraintData();
	QStringList columnNames() const;
	void appendColumn(TableColumn* col);
private:
	TableColumnList _cols;
};

#endif /*PRIMARYKEYCONSTRAINTDATA_H_*/
