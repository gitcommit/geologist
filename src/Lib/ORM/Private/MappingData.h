#ifndef MAPPINGDATA_H_
#define MAPPINGDATA_H_

#include <QtCore/qshareddata.h>

class Table;

class MappingData : public QSharedData {
public:
	MappingData(Table* t = 0);
	MappingData(const MappingData& other);
	virtual ~MappingData();
	void setTable(Table* t) { _table = t; }
	Table* table() const { return _table; }
	bool hasTable() const { return (0 != _table); }
private:
	Table* _table;
};

#endif /*MAPPINGDATA_H_*/
