#include <Entity.h>

#include <QtCore/QDebug>

Entity::Entity(QObject* p) :
	QObject(p) {
	connect(this, SIGNAL(dataChanged()), this, SLOT(onDataChanged()));
	setStatus(Entity::New);
}

Entity::Entity(const Entity& other) {
}

Entity::~Entity() {
}

void Entity::onDataChanged() {
	setStatus(Entity::Dirty);
	qDebug() << "Entity::onDataChanged()";
}