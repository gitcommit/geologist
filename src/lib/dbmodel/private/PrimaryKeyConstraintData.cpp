#include <private/PrimaryKeyConstraintData.h>

#include <QtCore/QStringList>

PrimaryKeyConstraintData::PrimaryKeyConstraintData(const QString& name) :
	ConstraintData(name) {
}

PrimaryKeyConstraintData::PrimaryKeyConstraintData(const PrimaryKeyConstraintData& other) :
	ConstraintData(other) {
}

PrimaryKeyConstraintData::~PrimaryKeyConstraintData() {
}
