/* 
 * File:   SIPrefixManager.cpp
 * Author: jolo
 * 
 * Created on 16. Dezember 2010, 17:10
 */

#include <Lib/Model/Core/SIPrefixManager.h>

#include <QtCore/QDebug>
#include <QtSql/QSqlField>

#include <Lib/ORM/Entity.h>
#include <Lib/ORM/Session.h>

#include <Lib/Tools/tools.h>

SIPrefixManager::SIPrefixManager(QObject* p, const QString& moduleName, const QString& className,
        const QString& schemaName, const QString& tableName)
: DataManager(p, moduleName, className, schemaName, tableName) {
    
}

SIPrefixManager::~SIPrefixManager() {
}

Entity* SIPrefixManager::newEntity() {
    return new SIPrefix(getApp()->session());
}
