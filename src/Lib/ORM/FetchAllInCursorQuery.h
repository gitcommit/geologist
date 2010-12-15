/* 
 * File:   FetchAllInCursorQuery.h
 * Author: jolo
 *
 * Created on 15. Dezember 2010, 09:08
 */

#ifndef FETCHALLINCURSORQUERY_H
#define	FETCHALLINCURSORQUERY_H

#include <Lib/ORM/CursorQuery.h>

class FetchAllInCursorQuery: public CursorQuery {
public:
    FetchAllInCursorQuery(const QString& cursorName = QString::null, const qulonglong& id = 0);
    FetchAllInCursorQuery(const FetchAllInCursorQuery& orig);
    virtual ~FetchAllInCursorQuery();
};

#endif	/* FETCHALLINCURSORQUERY_H */

