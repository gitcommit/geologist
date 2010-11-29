#ifndef ENTITY_H_
#define ENTITY_H_

#include <QtCore/qobject.h>

class Entity: public QObject
{
	Q_OBJECT
public:
	Entity(QObject* p=0);
	virtual ~Entity();
};

#endif /*ENTITY_H_*/
