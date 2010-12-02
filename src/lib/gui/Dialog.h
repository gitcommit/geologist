/* 
 * File:   Dialog.h
 * Author: jolo
 *
 * Created on 2. Dezember 2010, 13:05
 */

#ifndef DIALOG_H
#define	DIALOG_H

#include <QtGui/QDialog>

class Dialog: public QDialog {
    Q_OBJECT
public:
    Dialog(QWidget* p);
    virtual ~Dialog();
    virtual void addWidget(QWidget* w);
};

#endif	/* DIALOG_H */

