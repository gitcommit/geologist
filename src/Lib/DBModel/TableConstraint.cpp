#include <Lib/DBModel/TableConstraint.h>

#include <QtCore/QStringList>

#include <Lib/DBModel/Table.h>
#include <Lib/DBModel/DataType.h>

TableConstraint::TableConstraint(Table* table, const QString& name) :
	InTableModelComponent(table) {
}

TableConstraint::TableConstraint(const TableConstraint& other) {
}

TableConstraint::~TableConstraint() {
}
