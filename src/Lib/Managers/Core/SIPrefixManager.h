/* 
 * File:   SIPrefixManager.h
 * Author: jolo
 *
 * Created on 16. Dezember 2010, 09:58
 */

#ifndef SIPREFIXMANAGER_H
#define	SIPREFIXMANAGER_H

#include <Lib/Managers/Base/DataManager.h>

class SIPrefixManager: public DataManager {
    Q_OBJECT
public:
    SIPrefixManager(QObject* p = 0);
    virtual ~SIPrefixManager();
};

#endif	/* SIPREFIXMANAGER_H */

