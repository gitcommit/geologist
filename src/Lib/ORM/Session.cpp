/* 
 * File:   Session.cpp
 * Author: jolo
 * 
 * Created on 16. Dezember 2010, 19:51
 */

#include <Lib/ORM/Session.h>

#include <Lib/Tools/tools.h>

Session::Session()
: QObject(getApp()) {
}

Session::~Session() {
}

