#ifndef ENTITY_H_
#define ENTITY_H_

#include <QtCore/QMetaObject>

class Entity
{
 public:
  Entity();
  Entity(const Entity& other);
  virtual ~Entity();

  virtual void save();
  virtual void refresh();
  virtual void remove();
 protected:
  virtual void createOrUpdate();
  virtual void create();
  virtual void update();
};

#endif /*ENTITY_H_*/
