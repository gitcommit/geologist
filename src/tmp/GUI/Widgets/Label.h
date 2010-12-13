/* 
 * File:   Label.h
 * Author: jolo
 *
 * Created on 2. Dezember 2010, 13:11
 */

#ifndef LABEL_H
#define	LABEL_H

#include <QtGui/QLabel>

class Label: public QLabel {
    Q_OBJECT
public:
    Label(QWidget* p, const QString& txt);
    virtual ~Label();
private:

};

#endif	/* LABEL_H */

