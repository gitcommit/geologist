/* 
 * File:   CursorQuery.h
 * Author: jolo
 *
 * Created on 15. Dezember 2010, 09:34
 */

#ifndef CURSORQUERY_H
#define	CURSORQUERY_H

#include <Lib/ORM/Query.h>

class CursorQuery : public Query {
public:
    CursorQuery(const QString& cursorName = QString::null,
            const QString& sql = QString::null,
            const qulonglong& id = 0);
    CursorQuery(const CursorQuery& orig);
    virtual ~CursorQuery();

    void setCursorName(const QString& n) {
        _cursorName = n;
    }

    QString cursorName() const {
        return _cursorName;
    }
private:
    QString _cursorName;
};

#endif	/* CURSORQUERY_H */

