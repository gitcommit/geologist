/* 
 * File:   Query.h
 * Author: jolo
 *
 * Created on 15. Dezember 2010, 08:43
 */

#ifndef QUERY_H
#define	QUERY_H

#include <QtCore/QSharedData>

#include <QtCore/QString>
#include <QtCore/QList>
#include <QtSql/QSqlRecord>
#include <QtSql/QSqlQuery>

class Query {
public:
    Query(const QString& sql = QString::null, const qulonglong& id = 0);
    Query(const Query& orig);
    virtual ~Query();

    virtual void setSql(const QString& sql) {
        _sql = sql;
    }

    virtual QString sql() const {
        return _sql;
    }
    qulonglong id() const { return _id; }
    QList<QSqlRecord> records() const { return _res; }
    void loadRecordsFromQuery(QSqlQuery* q);
private:
    QString _sql;
    qulonglong _id;
    QList<QSqlRecord> _res;
};

#endif	/* QUERY_H */

