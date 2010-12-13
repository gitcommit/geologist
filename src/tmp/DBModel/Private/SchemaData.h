#ifndef SCHEMADATA_H_
#define SCHEMADATA_H_

#include <private/Base.h>

class SchemaData : public Base {
public:
	SchemaData(const QString& name = QString::null);
	SchemaData(const SchemaData& other);
	virtual ~SchemaData();
};

#endif /*SCHEMADATA_H_*/
