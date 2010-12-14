#ifndef TABLECOLUMNDATA_H_
#define TABLECOLUMNDATA_H_

#include <Lib/DBModel/private/Base.h>

class DataType;

class TableColumnData : public Base {
public:
	TableColumnData(const QString& name = QString::null, DataType* dataType = 0, const bool& nullable = false);
	TableColumnData(const TableColumnData& other);
	virtual ~TableColumnData();
	void setDataType(DataType* t) { _dataType = t; }
	void setNullable(const bool& b) { _nullable = b; }
	DataType* dataType() const { return _dataType; }
	bool nullable() const { return _nullable; }
private:
	DataType* _dataType;
	bool _nullable;
};

#endif /*TABLECOLUMNDATA_H_*/
