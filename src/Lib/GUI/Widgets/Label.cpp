/* 
 * File:   Label.cpp
 * Author: jolo
 * 
 * Created on 2. Dezember 2010, 13:11
 */

#include <Lib/GUI/Widgets/Label.h>

Label::Label(QWidget* p, const QString& txt)
: QLabel(txt, p) {
}

Label::~Label() {
}

