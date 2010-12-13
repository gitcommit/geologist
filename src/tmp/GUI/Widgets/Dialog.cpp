/* 
 * File:   Dialog.cpp
 * Author: jolo
 * 
 * Created on 2. Dezember 2010, 13:05
 */

#include <Dialog.h>

#include <QtGui/QLayout>

Dialog::Dialog(QWidget* p)
: QDialog(p) {
    setLayout(new QVBoxLayout(this));
}

Dialog::~Dialog() {
}

void Dialog::addWidget(QWidget* w) {
    layout()->addWidget(w);
}