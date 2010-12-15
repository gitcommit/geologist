/* 
 * File:   DeclareCursorQuery.cpp
 * Author: jolo
 * 
 * Declared on 15. Dezember 2010, 08:48
 */

#include <Lib/ORM/DeclareCursorQuery.h>

DeclareCursorQuery::DeclareCursorQuery(const QString& cn, const QString& sql, const qulonglong& id)
: CursorQuery(sql, QString::null, id) {
    setSql(QString("DECLARE %1 CURSOR FOR %2;").arg(cursorName()).arg(sql));
}

DeclareCursorQuery::DeclareCursorQuery(const DeclareCursorQuery& orig)
: CursorQuery(orig) {
}

DeclareCursorQuery::~DeclareCursorQuery() {
}

