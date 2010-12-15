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

class Query : public QSharedData {
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
private:
    QString _sql;
    qulonglong _id;
};

#endif	/* QUERY_H */

