#ifndef ENTITY_H_
#define ENTITY_H_

#include <QtCore/QObject>
#include <QtSql/QSqlRecord>

class Entity: public QObject
{
  Q_OBJECT
    public:
  Entity(QObject* p=0);
  virtual void save();
  virtual void refresh();
  virtual void remove();
  virtual ~Entity();
 protected:
  virtual void createOrUpdate();
  virtual void create();
  virtual void update();
};

#endif /*ENTITY_H_*/
