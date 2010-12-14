#include <Lib/DBModel/private/CheckConstraintData.h>

#include <QtCore/QStringList>

CheckConstraintData::CheckConstraintData(const QString& name, const QString& definition) :
	ConstraintData(name), _definition(definition) {
}

CheckConstraintData::CheckConstraintData(const CheckConstraintData& other) :
	ConstraintData(other), _definition(other._definition) {
}

CheckConstraintData::~CheckConstraintData() {
}
