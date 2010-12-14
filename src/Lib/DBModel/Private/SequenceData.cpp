#include <Lib/DBModel/Private/SequenceData.h>

SequenceData::SequenceData(const QString& name) :
	Base(name) {
}

SequenceData::SequenceData(const SequenceData& other) :
	Base(other) {
}

SequenceData::~SequenceData() {
}
