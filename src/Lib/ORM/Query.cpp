/* 
 * File:   Query.cpp
 * Author: jolo
 * 
 * Created on 15. Dezember 2010, 08:43
 */

#include <Lib/ORM/Query.h>

Query::Query(const QString& sql, const qulonglong& id)
: QSharedData(), _sql(sql), _id(id) {
}

Query::Query(const Query& orig)
: QSharedData(orig), _sql(orig._sql), _id(orig._id) {
}

Query::~Query() {
}

