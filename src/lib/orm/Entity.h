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

	Entity::States status() const { return _status; }
	virtual QString const toString() { return tr("Entity [%1]").arg(descriptiveStatus()); } 
	
	QString descriptiveStatus() const {
		switch(status()) {
		case(Entity::New): return tr("New");
		case(Entity::Dirty): return tr("Dirty");
		case(Entity::Clean): return tr("Clean");
		default: return tr("Unknowne");
		}
	}
signals:
	void dataChanged();
public slots:
	virtual void onDataChanged();
	virtual void setStatus(const Entity::States& s) { _status = s; }
private:
	Entity(const Entity& other);
	Entity::States _status;
};

#endif /*ENTITY_H_*/
