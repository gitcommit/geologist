#ifndef INSCHEMAMODELELEMENT_H_
#define INSCHEMAMODELELEMENT_H_

#include <DbModelElement.h>

class Schema;

class InSchemaModelElement: public DbModelElement
{
	Q_OBJECT
public:
	InSchemaModelElement(Schema* s = 0, const QString& name = QString::null);
	virtual ~InSchemaModelElement();
	virtual QString qualifiedName() const;
	Schema* schema() const;
};

#endif /*INSCHEMAMODELELEMENT_H_*/
