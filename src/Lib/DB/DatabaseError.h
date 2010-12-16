/* 
 * File:   DatabaseError.h
 * Author: jolo
 *
 * Created on 16. Dezember 2010, 10:19
 */

#ifndef DATABASEERROR_H
#define	DATABASEERROR_H

#include <QtSql/QSqlError>

class DatabaseError {
public:
    DatabaseError(const QSqlError& err);
    DatabaseError(const DatabaseError& orig);
    virtual ~DatabaseError();
    QSqlError error() const { return _e; }
    QString toString() const { return _e.text(); }
private:
    QSqlError _e;
};

#endif	/* DATABASEERROR_H */

