#ifndef IDENTIFIEDENTITY_H_
#define IDENTIFIEDENTITY_H_

#include <Entity.h>

class IdentifiedEntity: public Entity
{
	Q_OBJECT
	Q_PROPERTY(qulonglong id READ id WRITE setId)
public:
	IdentifiedEntity(QObject* p=0, const qulonglong& id=0);
	virtual ~IdentifiedEntity();
	void setId(const qulonglong& id) { id_ = id; }
	qulonglong id() const { return id_; }
	const bool hasId() const { return (id_ > 0); }
private:
	IdentifiedEntity(const IdentifiedEntity& other) {}
	qulonglong id_;
};

#endif /*IDENTIFIEDENTITY_H_*/
