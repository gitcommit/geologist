#include <TableConstraint.h>

#include <QtCore/QStringList>

#include <Table.h>
#include <DataType.h>

TableConstraint::TableConstraint(Table* table, const QString& name) :
	InTableModelComponent(table) {
}

TableConstraint::TableConstraint(const TableConstraint& other) {
}

TableConstraint::~TableConstraint() {
}
