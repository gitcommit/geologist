/* 
 * File:   DataManager.h
 * Author: jolo
 *
 * Created on 16. Dezember 2010, 09:55
 */

#ifndef DATAMANAGER_H
#define	DATAMANAGER_H

#include <QtCore/QObject>

#include <QtCore/QList>

#include <QtXML/QDomDocument>
#include <QtXML/QDomNode>

#include <Lib/ORM/DeclareSelectCursorQuery.h>
#include <Lib/ORM/FetchAllInCursorQuery.h>
#include <Lib/ORM/CloseCursorQuery.h>
#include <Lib/ORM/Mapping.h>

#include <Lib/DBModel/DBModel.h>
#include <Lib/DBModel/Schema.h>
#include <Lib/DBModel/Table.h>

class DataManager : public QObject {
    Q_OBJECT
public:
    DataManager(QObject* p = 0,
            const QString& moduleName = QString::null, const QString& className = QString::null,
            const QString& schemaName = QString::null, const QString& tableName = QString::null);
    virtual ~DataManager();
    Mapping* mapping() {
        return _mapping;
    }

signals:
    void execRequest(const DeclareSelectCursorQuery& q);
    void execRequest(const FetchAllInCursorQuery& q);
    void execRequest(const CloseCursorQuery& q);
public slots:
    virtual void loadAll();
    virtual void onQueryCompleted(const DeclareSelectCursorQuery& q);
    virtual void onQueryCompleted(const FetchAllInCursorQuery& q);

protected:
    virtual void configure();
    virtual void parseQueryResult(const FetchAllInCursorQuery& q);
    qulonglong nextQueryId();
    qulonglong queryId() const;
    bool isMyQuery(const Query* q) const;

    void setMapping(Mapping* m) {
        _mapping = m;
    }
    QString moduleName() const { return _moduleName; }
    QString className() const { return _className; }
    QString schemaName() const { return _schemaName; }
    QString tableName() const { return _tableName; }
private:
    qulonglong _qid;
    QString _mappingFileName;
    QString _moduleName;
    QString _className;
    QString _schemaName;
    QString _tableName;
    Mapping* _mapping;
};

typedef QList<DataManager*> DataManagerList;

#endif	/* DATAMANAGER_H */

