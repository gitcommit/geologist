/* 
 * File:   DataManager.h
 * Author: jolo
 *
 * Created on 16. Dezember 2010, 09:55
 */

#ifndef DATAMANAGER_H
#define	DATAMANAGER_H

#include <QtCore/QObject>

#include <Lib/ORM/DeclareSelectCursorQuery.h>
#include <Lib/ORM/FetchAllInCursorQuery.h>
#include <Lib/ORM/CloseCursorQuery.h>

class DataManager : public QObject {
    Q_OBJECT
public:
    DataManager(QObject* p = 0);
    virtual ~DataManager();
signals:
    void execRequest(const DeclareSelectCursorQuery& q);
    void execRequest(const FetchAllInCursorQuery& q);
    void execRequest(const CloseCursorQuery& q);
public slots:
    virtual void loadAll() = 0;
    virtual void onQueryCompleted(const DeclareSelectCursorQuery& q) = 0;
    virtual void onQueryCompleted(const FetchAllInCursorQuery& q) = 0;

protected:
    qulonglong qid;
};

#endif	/* DATAMANAGER_H */

