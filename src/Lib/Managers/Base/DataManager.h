/* 
 * File:   DataManager.h
 * Author: jolo
 *
 * Created on 16. Dezember 2010, 09:55
 */

#ifndef DATAMANAGER_H
#define	DATAMANAGER_H

#include <QtCore/QObject>

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
    DataManager(QObject* p = 0, const QString& mappingFileName = QString::null,
            const QString& moduleName = QString::null, const QString& className = QString::null);
    virtual ~DataManager();
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
    QString mappingFileName() const { return _mappingFileName; }
    QDomDocument domDocument() const;
    QDomNode moduleNode(const QString& moduleName);
    QDomNode classNode(const QString& moduleName, const QString& className);
    qulonglong nextQueryId();
    qulonglong queryId() const;
    bool isMyQuery(const Query* q) const;

    Mapping* mapping() {
        return _mapping;
    }

    void setMapping(Mapping* m) {
        _mapping = m;
    }
    QString moduleName() const { return _moduleName; }
    QString className() const { return _className; }
private:
    qulonglong _qid;
    QString _mappingFileName;
    QString _moduleName;
    QString _className;
    Mapping* _mapping;
};

#endif	/* DATAMANAGER_H */

