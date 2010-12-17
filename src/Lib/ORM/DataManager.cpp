/* 
 * File:   DataManager.cpp
 * Author: jolo
 * 
 * Created on 16. Dezember 2010, 09:55
 */

#include <Lib/ORM/DataManager.h>

#include <QtCore/QStringList>
#include <QtCore/QDebug>

#include <Lib/Tools/tools.h>

#include <Lib/DBModel/DBModel.h>
#include <Lib/DBModel/Schema.h>
#include <Lib/DBModel/Table.h>
#include <Lib/DBModel/TableColumn.h>

#include <Lib/ORM/Property.h>

DataManager::DataManager(QObject* p, const QString& modN, const QString& clN, const QString& sN, const QString& tN)
: QObject(p), _mapping(0), _moduleName(modN), _className(clN), _schemaName(sN), _tableName(tN) {
    setObjectName(QString("%1::%2").arg(modN).arg(clN));
    connect(this, SIGNAL(execRequest(const DeclareSelectCursorQuery&)), getApp()->databaseThread(), SLOT(onQueryRequest(const DeclareSelectCursorQuery&)));
    connect(this, SIGNAL(execRequest(const FetchAllInCursorQuery&)), getApp()->databaseThread(), SLOT(onQueryRequest(const FetchAllInCursorQuery&)));
    connect(this, SIGNAL(execRequest(const CloseCursorQuery&)), getApp()->databaseThread(), SLOT(onQueryRequest(const CloseCursorQuery&)));

    connect(getApp()->databaseThread(), SIGNAL(queryCompleted(const DeclareSelectCursorQuery&)), this, SLOT(onQueryCompleted(const DeclareSelectCursorQuery&)));
    connect(getApp()->databaseThread(), SIGNAL(queryCompleted(const FetchAllInCursorQuery&)), this, SLOT(onQueryCompleted(const FetchAllInCursorQuery&)));
    configure();
}

DataManager::~DataManager() {
}

qulonglong DataManager::nextQueryId() {
    _qid = getApp()->nextQueryId();
    return _qid;
}

qulonglong DataManager::queryId() const {
    return _qid;
}

bool DataManager::isMyQuery(const Query* q) const {
    Q_CHECK_PTR(q);
    return (q->id() == queryId());
}

void DataManager::loadAll() {
    emit execRequest(mapping()->declareSelectAllCursor(nextQueryId()));
}

void DataManager::onQueryCompleted(const DeclareSelectCursorQuery& q) {
    if (!isMyQuery(&q)) {
        return;
    }
    emit execRequest(mapping()->fetchAllInSelectAllCursor(nextQueryId()));
}

PropertyList DataManager::properties() const {
    Q_ASSERT(hasMapping());
    return mapping()->properties();
}

void DataManager::configure() {
    Schema* schema = getApp()->databaseModel()->schema(schemaName());
    Q_CHECK_PTR(schema);
    Table* table = schema->table(tableName());
    Q_CHECK_PTR(table);
    setMapping(new Mapping(table));
}

void DataManager::onQueryCompleted(const FetchAllInCursorQuery& q) {
    if (!isMyQuery(&q)) {
        return;
    }
    parseQueryResult(q);
    emit execRequest(mapping()->closeFetchAllCursor(nextQueryId()));
}

void DataManager::parseQueryResult(const FetchAllInCursorQuery& q) {
    QList<QSqlRecord> res = q.records();
    for (QList<QSqlRecord>::const_iterator it = res.begin(); it != res.end(); it++) {
        qDebug() << "loaded: " << fromRecord(*it)->toString();
    }
}

Entity* DataManager::fromRecord(const QSqlRecord& r) {
    Entity *e = newEntity();
    Q_CHECK_PTR(e);
    PropertyList pl = properties();
    for (PropertyList::const_iterator pit = pl.begin(); pit != pl.end(); pit++) {
        Property* p = (*pit);
        e->setProperty(p->name().toLocal8Bit(), r.field(p->tableColumn()->name()).value());
    }
    return e;
}