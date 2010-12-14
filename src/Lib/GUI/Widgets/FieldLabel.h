/* 
 * File:   FieldLabel.h
 * Author: jolo
 *
 * Created on 2. Dezember 2010, 13:12
 */

#ifndef FIELDLABEL_H
#define	FIELDLABEL_H

#include <Lib/GUI/Widgets/Label.h>

class FieldLabel: public Label {
    Q_OBJECT
public:
    FieldLabel(QWidget* p, const QString& lbl);
    virtual ~FieldLabel();
private:

};

#endif	/* FIELDLABEL_H */

