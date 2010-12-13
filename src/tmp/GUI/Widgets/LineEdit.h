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

class LineEdit : public QLineEdit {
	Q_OBJECT
public:
	LineEdit(QWidget* p, const QString& lbl, const QString& value=QString::null);
	virtual ~LineEdit();
	bool hasLabel() const {return (0 != lbl_);}
	FieldLabel* label() const {return lbl_;}
signals:
	void valueChanged(const QString& newValue);
	
protected slots:
	virtual void onTextChanged(const QString& txt);
private:
	FieldLabel* lbl_;
};

#endif	/* LINEEDIT_H */

