#ifndef TABLEMAPPING_H_
#define TABLEMAPPING_H_

#include <Lib/ORM/Mapping.h>

class Table;

class TableMapping : public Mapping {
	Q_OBJECT
public:
	TableMapping(QObject* p = 0, Table* t = 0);
	TableMapping(const TableMapping& other);
	virtual ~TableMapping();
	void setTable(Table* t);
};

#endif /*TABLEMAPPING_H_*/
