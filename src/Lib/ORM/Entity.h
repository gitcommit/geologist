#ifndef ENTITY_H_
#define ENTITY_H_

#include <QtCore/QMetaObject>
#include <QtCore/QObject>

#include <Lib/ORM/EntityStatus.h>

class Mapper;

class Entity : public QObject {
	Q_OBJECT
	Q_PROPERTY(EntityStatus status READ status WRITE setStatus)
public:
	Entity(QObject* p = 0);
	Entity(const Entity& other);
	virtual ~Entity();

	virtual EntityStatus status() const {return _status;}
	virtual void setStatus(const EntityStatus& s) {emit statusChanged(s); _status = s;}
	virtual QString statusText() const {return _status.toString();}

	virtual QString toString() const = 0;
signals:
	void dataChanged();
	void statusChanged(const EntityStatus& s);
public slots:
	virtual void onDataChanged();
protected:
	virtual Mapper* mapper() const = 0;
private:
	EntityStatus _status;
};

#endif /*ENTITY_H_*/
