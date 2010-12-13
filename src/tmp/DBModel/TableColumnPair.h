#ifndef TABLECOLUMNPAIR_H_
#define TABLECOLUMNPAIR_H_

#include <ModelComponent.h>

class TableColumn;

class TableColumnPair
{
public:
	TableColumnPair(TableColumn* left = 0, TableColumn* right = 0);
	virtual ~TableColumnPair();
	
	void setLeft(TableColumn* c) { _left = c; }
	void setRight(TableColumn* c) { _right = c; }
	TableColumn* left() const { return _left; }
	TableColumn* right() const { return _right; }
	virtual QString qualifiedName() const;
private:
	TableColumn* _left;
	TableColumn* _right;
};

typedef QList<TableColumnPair*> TableColumnPairList;

#endif /*TABLECOLUMNPAIR_H_*/
