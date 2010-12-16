/* 
 * File:   DatabaseError.cpp
 * Author: jolo
 * 
 * Created on 16. Dezember 2010, 10:19
 */

#include <Lib/DB/DatabaseError.h>

DatabaseError::DatabaseError(const QSqlError& e)
: _e(e) {
}

DatabaseError::DatabaseError(const DatabaseError& orig)
: _e(orig._e) {
}

DatabaseError::~DatabaseError() {
}

