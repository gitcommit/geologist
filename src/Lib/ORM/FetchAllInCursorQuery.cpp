/* 
 * File:   FetchAllInCursorQuery.cpp
 * Author: jolo
 * 
 * Created on 15. Dezember 2010, 09:08
 */

#include <Lib/ORM/FetchAllInCursorQuery.h>

FetchAllInCursorQuery::FetchAllInCursorQuery(const QString& cn, const qulonglong& id)
: CursorQuery(cn, QString::null, id) {
    setSql(QString("FETCH ALL IN %1;").arg(cn));
}

FetchAllInCursorQuery::FetchAllInCursorQuery(const FetchAllInCursorQuery& orig)
: CursorQuery(orig) {
}

FetchAllInCursorQuery::~FetchAllInCursorQuery() {
}

