#ifndef TABLECOLUMNDATA_H_
#define TABLECOLUMNDATA_H_

#include <private/Base.h>

class DataType;

class TableColumnData : public Base {
public:
	TableColumnData(const QString& name = QString::null, DataType* dataType = 0);
	TableColumnData(const TableColumnData& other);
	virtual ~TableColumnData();
	void setDataType(DataType* t) { _dataType = t; }
	DataType* dataType() const { return _dataType; }
private:
	DataType* _dataType;
};

#endif /*TABLECOLUMNDATA_H_*/
