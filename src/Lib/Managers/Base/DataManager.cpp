/* 
 * File:   DataManager.cpp
 * Author: jolo
 * 
 * Created on 16. Dezember 2010, 09:55
 */

#include <Lib/Managers/Base/DataManager.h>

#include <Lib/Tools/tools.h>

DataManager::DataManager(QObject* p)
: QObject(p) {
    connect(this, SIGNAL(execRequest(const DeclareSelectCursorQuery&)), getApp()->databaseThread(), SLOT(onQueryRequest(const DeclareSelectCursorQuery&)));
    connect(this, SIGNAL(execRequest(const FetchAllInCursorQuery&)), getApp()->databaseThread(), SLOT(onQueryRequest(const FetchAllInCursorQuery&)));
    connect(this, SIGNAL(execRequest(const CloseCursorQuery&)), getApp()->databaseThread(), SLOT(onQueryRequest(const CloseCursorQuery&)));

    connect(getApp()->databaseThread(), SIGNAL(queryCompleted(const DeclareSelectCursorQuery&)), this, SLOT(onQueryCompleted(const DeclareSelectCursorQuery&)));
    connect(getApp()->databaseThread(), SIGNAL(queryCompleted(const FetchAllInCursorQuery&)), this, SLOT(onQueryCompleted(const FetchAllInCursorQuery&)));
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

void DataManager::onQueryCompleted(const FetchAllInCursorQuery& q) {
    if (!isMyQuery(&q)) {
        return;
    }
    emit execRequest(mapping()->closeFetchAllCursor(nextQueryId()));
}