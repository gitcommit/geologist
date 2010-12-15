/* 
 * File:   CursorQuery.cpp
 * Author: jolo
 * 
 * Created on 15. Dezember 2010, 09:34
 */

#include <Lib/ORM/CursorQuery.h>

CursorQuery::CursorQuery(const QString& cursorName, const QString& sql, const qulonglong& id)
: Query(sql, id), _cursorName(cursorName) {
}

CursorQuery::CursorQuery(const CursorQuery& orig)
: Query(orig), _cursorName(orig._cursorName) {
}

CursorQuery::~CursorQuery() {
}

