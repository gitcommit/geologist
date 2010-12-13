#ifndef ENTITYDATA_H_
#define ENTITYDATA_H_

#include <QtCore/QSharedData>

class EntityData: public QSharedData {
public:
	EntityData();
	EntityData(const EntityData& other);
	virtual ~EntityData();
};

#endif /*ENTITYDATA_H_*/
