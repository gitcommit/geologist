/* 
 * File:   SmartGroupBox.cpp
 * Author: jolo
 * 
 * Created on 2. Dezember 2010, 13:31
 */

#include <Lib/GUI/Widgets/SmartGroupBox.h>

#include <QtGui/QLayout>

#include <Lib/GUI/Widgets/LineEdit.h>
#include <Lib/GUI/Widgets/FieldLabel.h>

SmartGroupBox::SmartGroupBox(QWidget* p, const QString& title) :
	GroupBox(p, title), lblCol_(0), wCol_(1), r_(0) {
	setLayout(new QGridLayout(this));
}

SmartGroupBox::~SmartGroupBox() {
}

void SmartGroupBox::addWidget(LineEdit* w) {
	(void) nextRow();
	(qobject_cast<QGridLayout*>(layout()))->addWidget(w->label(), row(), lblCol());
	(qobject_cast<QGridLayout*>(layout()))->addWidget(w, row(), widgetCol());
}