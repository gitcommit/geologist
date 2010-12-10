#include <Table.h>

#include <Schema.h>

Table::Table(Schema* s, const QString& name) :
	InSchemaModelElement(s, name) {
	s->registerTable(this);
}

Table::~Table() {
}

QStringList Table::create() const {
	QStringList ret;
	ret.append(QString("CREATE TABLE %1();").arg(qualifiedName()));
	return ret;
}