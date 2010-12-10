#ifndef ENTITY_H_
#define ENTITY_H_

#include <QtCore/QMetaObject>
#include <QtCore/QObject>

class Entity : public QObject {
	Q_OBJECT
	Q_PROPERTY(Entity::States status READ status WRITE setStatus)
public:
	enum States {
		New = 0,
		Dirty,
		Clean
	};
	Entity(QObject* p = 0);
	virtual ~Entity();

	virtual void save();
	virtual void refresh();
	virtual void remove();
	Entity::States status() const { return _status; }
signals:
	void dataChanged();
public slots:
	void onDataChanged();
protected:
	virtual void createOrUpdate();
	virtual void create();
	virtual void update();
	virtual void setStatus(const Entity::States& s) { _status = s; }
private:
	Entity(const Entity& other);
	Entity::States _status;
};

#endif /*ENTITY_H_*/
