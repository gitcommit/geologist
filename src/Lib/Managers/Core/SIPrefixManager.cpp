/* 
 * File:   SIPrefixManager.cpp
 * Author: jolo
 * 
 * Created on 16. Dezember 2010, 09:58
 */

#include <Lib/Managers/Core/SIPrefixManager.h>

#include <Lib/Tools/tools.h>

SIPrefixManager::SIPrefixManager(QObject* p)
: DataManager(p) {
}

SIPrefixManager::~SIPrefixManager() {
}

void SIPrefixManager::loadAll() {
    qid = getApp()->nextQueryId();

    emit execRequest(DeclareSelectCursorQuery("select_all_si_prefixes",
            "select id, name, code, symbol, factor, description from core.si_prefixes order by name asc",
            qid));
}

void SIPrefixManager::onQueryCompleted(const DeclareSelectCursorQuery& q) {
    if (q.id() != qid) {
        return;
    }
    qid = getApp()->nextQueryId();
    emit execRequest(FetchAllInCursorQuery(q.cursorName(), qid));
}

void SIPrefixManager::onQueryCompleted(const FetchAllInCursorQuery& q) {
    if (q.id() != qid) {
        return;
    }
    emit execRequest(CloseCursorQuery(q.cursorName(), getApp()->nextQueryId()));
}