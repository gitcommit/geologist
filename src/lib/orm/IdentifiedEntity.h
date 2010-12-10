#ifndef IDENTIFIEDENTITY_H_
#define IDENTIFIEDENTITY_H_

#include <Entity.h>

class IdentifiedEntity : public Entity {
	Q_OBJECT
	Q_PROPERTY(qulonglong id READ id WRITE setId NOTIFY idChanged)
public:
	IdentifiedEntity(QObject* p=0, const qulonglong& id=0);
	virtual ~IdentifiedEntity();
	void setId(const qulonglong& id) {_id = id; emit idChanged(); }
	qulonglong id() const {return _id;}
	const bool hasId() const {return (_id> 0);}
	virtual QString toString() const { return tr("Identified Entity with ID %1").arg(id()); }
signals:
	void idChanged();
private:
	IdentifiedEntity(const IdentifiedEntity& other) {}
	qulonglong _id;
};

#endif /*IDENTIFIEDENTITY_H_*/
