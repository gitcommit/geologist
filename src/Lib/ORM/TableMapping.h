#ifndef TABLEMAPPING_H_
#define TABLEMAPPING_H_

#include <Lib/ORM/Mapping.h>

class Table;

class TableMapping : public Mapping {
	Q_OBJECT
public:
	TableMapping(QObject* p = 0, Table* t = 0);
	virtual ~TableMapping();
};

#endif /*TABLEMAPPING_H_*/
