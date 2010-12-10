#ifndef SEQUENCE_H_
#define SEQUENCE_H_

#include <InSchemaModelElement.h>

class Sequence: public InSchemaModelElement
{
	Q_OBJECT
public:
	Sequence(Schema* schema = 0, const QString& name = QString::null);
	virtual ~Sequence();
	virtual QStringList create() const;
};

#endif /*SEQUENCE_H_*/
