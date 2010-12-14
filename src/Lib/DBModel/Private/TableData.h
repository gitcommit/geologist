#ifndef TABLEDATA_H_
#define TABLEDATA_H_

#include <Lib/DBModel/private/Base.h>

class TableData : public Base {
public:
	TableData(const QString& name = QString::null);
	TableData(const TableData& other);
	virtual ~TableData();
};

#endif /*TABLEDATA_H_*/
