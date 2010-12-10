#ifndef DATATYPEDATA_H_
#define DATATYPEDATA_H_

#include <private/Base.h>

class DataTypeData : public Base {
public:
	DataTypeData(const QString& name = QString::null,
			const QString& sqlName = QString::null);
	DataTypeData(const DataTypeData& other);
	virtual ~DataTypeData();
	void setSqlName(const QString& n) { _sqlName = n; }
	QString sqlName() const { return _sqlName; }
private:
	QString _sqlName;
};

#endif /*DATATYPEDATA_H_*/
