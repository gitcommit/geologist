#ifndef PRIMARYKEYCONSTRAINTDATA_H_
#define PRIMARYKEYCONSTRAINTDATA_H_

#include <private/ConstraintData.h>

#include <TableColumn.h>

class PrimaryKeyConstraintData : public ConstraintData {
public:
	PrimaryKeyConstraintData(const QString& name = QString::null);
	PrimaryKeyConstraintData(const PrimaryKeyConstraintData& other);
	virtual ~PrimaryKeyConstraintData();
};

#endif /*PRIMARYKEYCONSTRAINTDATA_H_*/
