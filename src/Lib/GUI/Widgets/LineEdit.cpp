/* 
 * File:   LineEdit.cpp
 * Author: jolo
 * 
 * Created on 2. Dezember 2010, 13:10
 */

#include <LineEdit.h>

#include <FieldLabel.h>
#include <SmartGroupBox.h>

LineEdit::LineEdit(QWidget* p, const QString& lbl, const QString& txt)
: QLineEdit(p),
lbl_(0) {
	setText(txt);
    if (!lbl.isEmpty()) {
        lbl_ = new FieldLabel(qobject_cast<QWidget*>(parent()), lbl);
        lbl_->setBuddy(this);
    }
    if (parent()->inherits("SmartGroupBox")) {
    	(qobject_cast<SmartGroupBox*>(parent()))->addWidget(this);
    }
    connect(this, SIGNAL(textChanged(const QString&)), this, SLOT(onTextChanged(const QString&)));
}

LineEdit::~LineEdit() {
}

void LineEdit::onTextChanged(const QString& msg) {
	emit valueChanged(msg);
}