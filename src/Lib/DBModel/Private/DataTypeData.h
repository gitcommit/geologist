#ifndef DATATYPEDATA_H_
#define DATATYPEDATA_H_

#include <Lib/DBModel/Private/Base.h>

class DataTypeData : public Base {
public:
	DataTypeData(const QString& name = QString::null,
			const QString& sqlName = QString::null,
			const bool& requiresQuoting = false);
	DataTypeData(const DataTypeData& other);
	virtual ~DataTypeData();
	void setRequiresQuoting(const bool& b) { _requiresQuoting = b; }
	void setSqlName(const QString& n) { _sqlName = n; }
	QString sqlName() const { return _sqlName; }
	bool requiresQuoting() const { return _requiresQuoting; }
private:
	QString _sqlName;
	bool _requiresQuoting;
};

#endif /*DATATYPEDATA_H_*/
