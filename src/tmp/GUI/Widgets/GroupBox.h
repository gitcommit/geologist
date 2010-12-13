/* 
 * File:   GroupBox.h
 * Author: jolo
 *
 * Created on 2. Dezember 2010, 13:23
 */

#ifndef GROUPBOX_H
#define	GROUPBOX_H

#include <QtGui/QGroupBox>

class GroupBox: public QGroupBox {
    Q_OBJECT
public:
    GroupBox(QWidget* p = 0, const QString& title=QString::null);
    virtual ~GroupBox();
private:

};

#endif	/* GROUPBOX_H */

