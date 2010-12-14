#ifndef IDENTIFIEDENTITY_H_
#define IDENTIFIEDENTITY_H_

#include <Lib/ORM/Entity.h>

class IdentifiedEntity : public Entity {
	Q_OBJECT
	Q_PROPERTY(qulonglong id READ id WRITE setId NOTIFY idChanged)
public:
	IdentifiedEntity(QObject* p=0, const qulonglong& id=0);
	IdentifiedEntity(const IdentifiedEntity& other);
	virtual ~IdentifiedEntity();
	virtual void setId(const qulonglong& id) = 0;
	virtual qulonglong id() const = 0;
	virtual bool hasId() const = 0;
signals:
	void idChanged(const qulonglong& newId);
};

#endif /*IDENTIFIEDENTITY_H_*/
