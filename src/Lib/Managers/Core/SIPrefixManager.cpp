/* 
 * File:   SIPrefixManager.cpp
 * Author: jolo
 * 
 * Created on 16. Dezember 2010, 09:58
 */

#include <Lib/Managers/Core/SIPrefixManager.h>

#include <Lib/Tools/tools.h>

#include <QtCore/QDebug>
SIPrefixManager::SIPrefixManager(QObject* p)
: DataManager(p) {
    setMapping(Mapping(getApp()->databaseModel()->schema("core")->table("si_prefixes")));
}

SIPrefixManager::~SIPrefixManager() {
}
