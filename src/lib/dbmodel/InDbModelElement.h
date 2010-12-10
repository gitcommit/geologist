#ifndef INMODELELEMENT_H_
#define INMODELELEMENT_H_

#include <DbModelElement.h>

class DbModel;

class InDbModelElement : public DbModelElement
{
	Q_OBJECT
public:
	InDbModelElement(DbModel* p = 0, const QString& name = QString::null);
	virtual ~InDbModelElement();
private:
	InDbModelElement(const InDbModelElement& other) {}
};

#endif /*INMODELELEMENT_H_*/
