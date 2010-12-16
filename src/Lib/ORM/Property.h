/* 
 * File:   Property.h
 * Author: jolo
 *
 * Created on 16. Dezember 2010, 13:22
 */

#ifndef PROPERTY_H
#define	PROPERTY_H

#include <QtCore/QObject>
#include <QtCore/QString>
#include <QtCore/QList>

class Mapping;
class TableColumn;

class Property: public QObject {
    Q_OBJECT
public:
    Property(Mapping* m = 0, const QString& name = QString::null, TableColumn* col = 0);
    virtual ~Property();
    Mapping* mapping() const;
    TableColumn* tableColumn() const { return _col; }
    
private:
    TableColumn* _col;
};

typedef QList<Property*> PropertyList;

#endif	/* PROPERTY_H */

