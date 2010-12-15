/* 
 * File:   DeclareSelectCursorQuery.cpp
 * Author: jolo
 * 
 * Created on 15. Dezember 2010, 09:50
 */

#include <Lib/ORM/DeclareSelectCursorQuery.h>

DeclareSelectCursorQuery::DeclareSelectCursorQuery(const QString& cn, const QString& sql)
: DeclareCursorQuery(cn, sql) {
}

DeclareSelectCursorQuery::DeclareSelectCursorQuery(const DeclareSelectCursorQuery& orig)
: DeclareCursorQuery(orig) {
}

DeclareSelectCursorQuery::~DeclareSelectCursorQuery() {
}

