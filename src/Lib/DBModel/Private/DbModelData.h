#ifndef DBMODELDATA_H_
#define DBMODELDATA_H_

#include <private/Base.h>

class DbModelData: public Base {
public:
	DbModelData(const QString& name = QString::null);
	DbModelData(const DbModelData& other);
	virtual ~DbModelData();
};

#endif /*DBMODELDATA_H_*/
