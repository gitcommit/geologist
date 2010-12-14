#ifndef IDENTIFIEDENTITYDATA_H_
#define IDENTIFIEDENTITYDATA_H_

#include <Lib/ORM/Private/EntityData.h>

class IdentifiedEntityData : public EntityData {
public:
	IdentifiedEntityData(const qulonglong& id = 0);
	IdentifiedEntityData(const IdentifiedEntityData& other);
	virtual ~IdentifiedEntityData();

	virtual void setId(const qulonglong& id) {
		_id = id;
	}
	virtual qulonglong id() const {
		return _id;
	}
	virtual bool hasId() const {
		return (id() > 0);
	}
private:
	qulonglong _id;
};

#endif /*IDENTIFIEDENTITYDATA_H_*/
