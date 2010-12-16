/* 
 * File:   Property.cpp
 * Author: jolo
 * 
 * Created on 16. Dezember 2010, 13:22
 */

#include <Lib/ORM/Property.h>

#include <Lib/ORM/Mapping.h>

Property::Property(Mapping* m, const QString& name, TableColumn* col)
: QObject(m), _col(col) {
}

Property::~Property() {
}

Mapping* Property::mapping() const {
    Q_CHECK_PTR(parent());
    return qobject_cast<Mapping*>(parent());
}