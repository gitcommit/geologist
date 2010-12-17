#ifndef ENTITY_H_
#define ENTITY_H_

#include <QtCore/QMetaObject>
#include <QtCore/QObject>

#include <Lib/ORM/EntityStatus.h>

class Entity : public QObject {
    Q_OBJECT
    Q_PROPERTY(EntityStatus status READ status WRITE setStatus)
public:
    Entity(QObject* p = 0);
    Entity(const Entity& other);
    virtual ~Entity();

    virtual EntityStatus status() const;
    virtual void setStatus(const EntityStatus& s);
    virtual QString statusText() const;

    virtual QString toString() const {
        return tr("Not Implemented");
    }
signals:
    void dataChanged();
    void statusChanged(const EntityStatus& s);
public slots:
    virtual void onDataChanged();
private:
    EntityStatus _status;
};

#endif /*ENTITY_H_*/
