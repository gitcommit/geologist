#include <private/UniqueConstraintData.h>

#include <QtCore/QStringList>

UniqueConstraintData::UniqueConstraintData(const QString& name) :
	ConstraintData(name) {
}

UniqueConstraintData::UniqueConstraintData(const UniqueConstraintData& other) :
	ConstraintData(other) {
}

UniqueConstraintData::~UniqueConstraintData() {
}
