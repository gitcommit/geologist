#include <Lib/ORM/Entity.h>

#include <QtCore/QCoreApplication>

Entity::Entity(QObject* p) :
	QObject(p) {
	connect(this, SIGNAL(dataChanged()), this, SLOT(onDataChanged()));
	setStatus(EntityStatus(EntityStatus::New));
}

Entity::Entity(const Entity& other) :
	_status(other._status) {
}

Entity::~Entity() {
}

void Entity::onDataChanged() {
	setStatus(EntityStatus(EntityStatus::Dirty));
}
