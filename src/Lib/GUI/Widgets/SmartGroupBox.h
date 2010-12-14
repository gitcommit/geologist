/* 
 * File:   SmartGroupBox.h
 * Author: jolo
 *
 * Created on 2. Dezember 2010, 13:31
 */

#ifndef SMARTGROUPBOX_H
#define	SMARTGROUPBOX_H

#include <Lib/GUI/Widgets/GroupBox.h>

class LineEdit;

class SmartGroupBox : public GroupBox {
	Q_OBJECT
public:
	SmartGroupBox(QWidget* p, const QString& txt);
	virtual ~SmartGroupBox();
	void addWidget(LineEdit* w);

protected:
	int nextRow() {r_++; return r_;}
	int row() const {return r_;}
	int lblCol() const {return lblCol_;}
	int widgetCol() const {return wCol_;}
private:
	int lblCol_;
	int wCol_;
	int r_;
};

#endif	/* SMARTGROUPBOX_H */

