#ifndef ENTITY_H_
#define ENTITY_H_

#include <QtCore/QMetaObject>
#include <QtCore/QObject>

class Entity: public QObject
{
	Q_OBJECT
 public:
  Entity(QObject* p = 0);
  virtual ~Entity();

  virtual void save();
  virtual void refresh();
  virtual void remove();
 protected:
  virtual void createOrUpdate();
  virtual void create();
  virtual void update();
 private:
   Entity(const Entity& other);
};

#endif /*ENTITY_H_*/
