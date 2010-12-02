/* 
 * File:   LineEdit.cpp
 * Author: jolo
 * 
 * Created on 2. Dezember 2010, 13:10
 */

#include <LineEdit.h>

#include <FieldLabel.h>

LineEdit::LineEdit(QWidget* p, const QString& lbl)
: QLineEdit(p),
lbl_(0) {
    if (!lbl.isEmpty()) {
        lbl_ = new FieldLabel(qobject_cast<QWidget*>(parent()), lbl);
    }
}

LineEdit::~LineEdit() {
}

