/* 
 * File:   CloseCursorQuery.cpp
 * Author: jolo
 * 
 * Created on 15. Dezember 2010, 09:46
 */

#include <Lib/ORM/CloseCursorQuery.h>

CloseCursorQuery::CloseCursorQuery(const QString& cn, const qulonglong& id)
: CursorQuery(cn, QString::null, id) {
    setSql(QString("CLOSE %1;").arg(cursorName()));
}

CloseCursorQuery::CloseCursorQuery(const CloseCursorQuery& orig) {
}

CloseCursorQuery::~CloseCursorQuery() {
}

