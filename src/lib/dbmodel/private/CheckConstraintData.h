#ifndef CHECKCONSTRAINTDATA_H_
#define CHECKCONSTRAINTDATA_H_

#include <private/ConstraintData.h>

#include <TableColumn.h>

class CheckConstraintData : public ConstraintData {
public:
	CheckConstraintData(const QString& name = QString::null, const QString& definition = QString::null);
	CheckConstraintData(const CheckConstraintData& other);
	virtual ~CheckConstraintData();
	void setDefinition(const QString& v) { _definition = v; }
	QString definition() const { return _definition; }
	
private:
	QString _definition;
};

#endif /*CHECKCONSTRAINTDATA_H_*/
