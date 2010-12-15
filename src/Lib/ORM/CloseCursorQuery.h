/* 
 * File:   CloseCursorQuery.h
 * Author: jolo
 *
 * Created on 15. Dezember 2010, 09:46
 */

#ifndef CLOSECURSORQUERY_H
#define	CLOSECURSORQUERY_H

#include <Lib/ORM/CursorQuery.h>

class CloseCursorQuery: public CursorQuery {
public:
    CloseCursorQuery(const QString& cursorName = QString::null, const qulonglong& id = 0);
    CloseCursorQuery(const CloseCursorQuery& orig);
    virtual ~CloseCursorQuery();
};

#endif	/* CLOSECURSORQUERY_H */

