#ifndef UNIQUECONSTRAINTDATA_H_
#define UNIQUECONSTRAINTDATA_H_

#include <private/ConstraintData.h>

#include <TableColumn.h>

class UniqueConstraintData : public ConstraintData {
public:
	UniqueConstraintData(const QString& name = QString::null);
	UniqueConstraintData(const UniqueConstraintData& other);
	virtual ~UniqueConstraintData();
};

#endif /*UNIQUECONSTRAINTDATA_H_*/
