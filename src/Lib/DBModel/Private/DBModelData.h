#ifndef DBMODELDATA_H_
#define DBMODELDATA_H_

#include <Lib/DBModel/Private/Base.h>

class DBModelData: public Base {
public:
	DBModelData(const QString& name = QString::null);
	DBModelData(const DBModelData& other);
	virtual ~DBModelData();
};

#endif /*DBMODELDATA_H_*/
