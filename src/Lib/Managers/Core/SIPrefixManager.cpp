/* 
 * File:   SIPrefixManager.cpp
 * Author: jolo
 * 
 * Created on 16. Dezember 2010, 09:58
 */

#include <Lib/Managers/Core/SIPrefixManager.h>

#include <QtCore/QDebug>
#include <QtCore/QStringList>


SIPrefixManager::SIPrefixManager(QObject* p, const QString& configFileName)
: DataManager(p, configFileName) {
}

SIPrefixManager::~SIPrefixManager() {
}
