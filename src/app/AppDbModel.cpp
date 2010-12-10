#include "AppDbModel.h"

#include <dbconfig.h>

#include <Schema.h>
#include <DataType.h>
#include <Schema.h>
#include <Sequence.h>
#include <Table.h>

AppDbModel::AppDbModel(QObject* p, const QString& name) :
	DbModel(p, name) {
	configure();
}

AppDbModel::~AppDbModel() {
}

void AppDbModel::configure() {
	(void) new Schema(this, CORE_SCHEMA_NAME);
	(void) new DataType(this, TYPE_INT_NAME, TYPE_INT_SQL_NAME);
	(void) new DataType(this, TYPE_TEXT_NAME, TYPE_TEXT_SQL_NAME);
	(void) new DataType(this, TYPE_DATE_NAME, TYPE_DATE_SQL_NAME);
	(void) new DataType(this, TYPE_TIME_NAME, TYPE_TIME_SQL_NAME);
	(void) new DataType(this, TYPE_TIMESTAMP_NAME, TYPE_TIMESTAMP_SQL_NAME);
	(void) new DataType(this, TYPE_NUMBER_NAME, TYPE_NUMBER_SQL_NAME);
	(void) new Sequence(schema(CORE_SCHEMA_NAME), SEQ_SI_PREFIXES);
	(void) new Table(schema(CORE_SCHEMA_NAME), TBL_SI_PREFIXES);
}