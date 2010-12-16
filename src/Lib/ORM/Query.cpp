/* 
 * File:   Query.cpp
 * Author: jolo
 * 
 * Created on 15. Dezember 2010, 08:43
 */

#include <Lib/ORM/Query.h>

#include <QtCore/QDebug>

Query::Query(const QString& sql, const qulonglong& id)
: _sql(sql), _id(id) {
}

Query::Query(const Query& orig)
: _sql(orig._sql), _id(orig._id) {
}

Query::~Query() {
}

void Query::loadRecordsFromQuery(QSqlQuery* q) {
    Q_CHECK_PTR(q);
    if (!q->isActive()) {
        return;
    }
    while (q->next()) {
        _res.append(q->record());
    }
}

