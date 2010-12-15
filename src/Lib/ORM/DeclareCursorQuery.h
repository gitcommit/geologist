/* 
 * File:   DeclareCursorQuery.h
 * Author: jolo
 *
 * Declared on 15. Dezember 2010, 08:48
 */

#ifndef DECLARECURSORQUERY_H
#define	DECLARECURSORQUERY_H

#include <Lib/ORM/CursorQuery.h>

class DeclareCursorQuery : public CursorQuery {
public:
    DeclareCursorQuery(const QString& cursorName = QString::null, const QString& sql = QString::null, const qulonglong& id = 0);
    DeclareCursorQuery(const DeclareCursorQuery& orig);
    virtual ~DeclareCursorQuery();
};

#endif	/* DECLARECURSORQUERY_H */

