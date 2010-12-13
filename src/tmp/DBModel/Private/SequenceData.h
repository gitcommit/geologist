#ifndef SEQUENCEDATA_H_
#define SEQUENCEDATA_H_

#include <private/Base.h>

class SequenceData : public Base {
public:
	SequenceData(const QString& name = QString::null);
	SequenceData(const SequenceData& other);
	virtual ~SequenceData();
};

#endif /*SEQUENCEDATA_H_*/
