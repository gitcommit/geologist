#include <Lib/DBModel/TableColumnPair.h>

#include <Lib/DBModel/TableColumn.h>

TableColumnPair::TableColumnPair(TableColumn* l, TableColumn* r) :
	_left(l), _right(r) {
}

TableColumnPair::~TableColumnPair() {
}

QString TableColumnPair::qualifiedName() const {
	return QString("%1 --> %2").arg(left()->qualifiedName()).arg(right()->qualifiedName());
}