/* 
 * File:   DeclareSelectCursorQuery.h
 * Author: jolo
 *
 * Created on 15. Dezember 2010, 09:50
 */

#ifndef DECLARESELECTCURSORQUERY_H
#define	DECLARESELECTCURSORQUERY_H

#include <Lib/ORM/DeclareCursorQuery.h>

class DeclareSelectCursorQuery: public DeclareCursorQuery {
public:
    DeclareSelectCursorQuery(const QString& cursorName = QString::null,
            const QString& sql = QString::null,
            const qulonglong& qid = 0);
    DeclareSelectCursorQuery(const DeclareSelectCursorQuery& orig);
    virtual ~DeclareSelectCursorQuery();
private:

};

#endif	/* DECLARESELECTCURSORQUERY_H */

