/* 
 * File:   DeclareCursorQuery.cpp
 * Author: jolo
 * 
 * Declared on 15. Dezember 2010, 08:48
 */

#include <Lib/ORM/DeclareCursorQuery.h>

DeclareCursorQuery::DeclareCursorQuery(const QString& cn, const QString& sqlBuf, const qulonglong& id)
: CursorQuery(cn, sqlBuf, id) {
    setSql(QString("DECLARE %1 CURSOR FOR %2;").arg(cn).arg(sqlBuf));
}

DeclareCursorQuery::DeclareCursorQuery(const DeclareCursorQuery& orig)
: CursorQuery(orig) {
}

DeclareCursorQuery::~DeclareCursorQuery() {
}

