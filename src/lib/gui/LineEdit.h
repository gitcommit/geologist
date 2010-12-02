/* 
 * File:   LineEdit.h
 * Author: jolo
 *
 * Created on 2. Dezember 2010, 13:10
 */

#ifndef LINEEDIT_H
#define	LINEEDIT_H

#include <QtGui/QLineEdit>

class FieldLabel;

class LineEdit: public QLineEdit {
    Q_OBJECT
public:
    LineEdit(QWidget* p, const QString& lbl);
    virtual ~LineEdit();
    bool hasLabel() const { return (0 != lbl_); }
private:
    FieldLabel* lbl_;
};

#endif	/* LINEEDIT_H */

