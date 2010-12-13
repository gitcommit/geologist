#ifndef IDENTIFIEDENTITY_H_
#define IDENTIFIEDENTITY_H_

#include <Entity.h>

class IdentifiedEntityData;

class IdentifiedEntity : public Entity {
	Q_OBJECT
	Q_PROPERTY(qulonglong id READ id WRITE setId NOTIFY idChanged)
public:
	IdentifiedEntity(QObject* p=0, const qulonglong& id=0);
	IdentifiedEntity(const IdentifiedEntity& other);
	virtual ~IdentifiedEntity();
	void setId(const qulonglong& id);
	qulonglong id() const;
	bool hasId() const;
	virtual QString toString() const { return tr("Identified Entity with ID %1").arg(id()); }
protected:
	IdentifiedEntityData* identifiedEntityData() const;
signals:
	void idChanged(const qulonglong& newId);
};

#endif /*IDENTIFIEDENTITY_H_*/
