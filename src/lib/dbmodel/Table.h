#ifndef TABLE_H_
#define TABLE_H_

#include <InSchemaModelElement.h>

class Schema;

class Table: public InSchemaModelElement
{
	Q_OBJECT
public:
	Table(Schema* schema=0, const QString& name=QString::null);
	virtual ~Table();
	virtual QStringList create() const;
};

#endif /*TABLE_H_*/
