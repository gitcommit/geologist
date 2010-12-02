/* 
 * File:   SmartGroupBox.h
 * Author: jolo
 *
 * Created on 2. Dezember 2010, 13:31
 */

#ifndef SMARTGROUPBOX_H
#define	SMARTGROUPBOX_H

#include <GroupBox.h>

class SmartGroupBox: public GroupBox {
    Q_OBJECT
public:
    SmartGroupBox(QWidget* p, const QString& txt);
    virtual ~SmartGroupBox();
private:

};

#endif	/* SMARTGROUPBOX_H */

