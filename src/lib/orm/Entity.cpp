#include <Entity.h>

Entity::Entity(QObject* p) :
  QObject(p) {
}

Entity::~Entity() {
}

void Entity::save() {}
void Entity::refresh() {}
void Entity::remove() {}
void Entity::createOrUpdate() {}
void Entity::create() {}
void Entity::update() {} 
