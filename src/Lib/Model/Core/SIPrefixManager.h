/* 
 * File:   SIPrefixManager.h
 * Author: jolo
 *
 * Created on 16. Dezember 2010, 17:10
 */

#ifndef SIPREFIXMANAGER_H
#define	SIPREFIXMANAGER_H

#include <Lib/ORM/DataManager.h>

class Entity;

class SIPrefixManager : public DataManager {
    Q_OBJECT
public:
    SIPrefixManager(QObject* p = 0,
            const QString& moduleName = QString::null, const QString& className = QString::null,
            const QString& schemaName = QString::null, const QString& tableName = QString::null);
    virtual ~SIPrefixManager();
    virtual Entity* newEntity();
};

#endif	/* SIPREFIXMANAGER_H */

