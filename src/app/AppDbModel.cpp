#include "AppDbModel.h"

#include <dbconfig.h>

#include <Schema.h>

AppDbModel::AppDbModel(QObject* p, const QString& name) :
	DbModel(p, name) {
	configure();
}

AppDbModel::~AppDbModel() {
}

void AppDbModel::configure() {
	Schema* core = createSchema(CORE_SCHEMA_NAME);
	createDataType(TYPE_INT_NAME, TYPE_INT_SQL_NAME);
	createDataType(TYPE_TEXT_NAME, TYPE_TEXT_SQL_NAME);
	createDataType(TYPE_DATE_NAME, TYPE_DATE_SQL_NAME);
	createDataType(TYPE_TIME_NAME, TYPE_TIME_SQL_NAME);
	createDataType(TYPE_TIMESTAMP_NAME, TYPE_TIMESTAMP_SQL_NAME);
	createDataType(TYPE_NUMBER_NAME, TYPE_NUMBER_SQL_NAME);
	core->createSequence(SEQ_SI_PREFIXES);
}