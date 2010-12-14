#include <Lib/ORM/Entity.h>

#include <QtCore/QCoreApplication>

#include <App/App.h>

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
}

App* Entity::app() const {
	return qobject_cast<App*>(QApplication::instance());
}