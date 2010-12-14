#include <Lib/ORM/Entity.h>

#include <QtCore/QCoreApplication>

#include <App/App.h>

Entity::Entity(QObject* p) :
	QObject(p), _d(0) {
	connect(this, SIGNAL(dataChanged()), this, SLOT(onDataChanged()));
	setStatus(Entity::New);
}

Entity::Entity(const Entity& other) :
	_d(other._d) {
}

Entity::~Entity() {
}

void Entity::onDataChanged() {
	setStatus(Entity::Dirty);
}

App* Entity::app() const {
	return qobject_cast<App*>(QApplication::instance());
}