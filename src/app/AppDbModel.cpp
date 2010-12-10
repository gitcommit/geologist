#include "AppDbModel.h"

#include <dbconfig.h>

#include <Schema.h>
#include <Table.h>
#include <DataType.h>

AppDbModel::AppDbModel(QObject* p, const QString& name) :
	DbModel(p, name) {
	configure();
}

AppDbModel::~AppDbModel() {
}

void AppDbModel::configure() {
	 Schema* core = new Schema(this, CORE_SCHEMA);
	 Schema* geology = new Schema(this, GEOLOGY_SCHEMA);
	 Schema* chemistry = new Schema(this, CHEMISTRY_SCHEMA);
	 (void) new Table(core, TBL_SI_PREFIXES);
	 (void) new Table(core, TBL_UNITS);
	 (void) new Table(core, TBL_UNIT_CONVERSIONS);
	 
	 (void) new DataType(this, TYPE_INT, TYPE_INT_SQL);
	 (void) new DataType(this, TYPE_TEXT, TYPE_TEXT_SQL);
	 (void) new DataType(this, TYPE_DATE, TYPE_DATE_SQL);
	 (void) new DataType(this, TYPE_TIME, TYPE_TIME_SQL);
	 (void) new DataType(this, TYPE_TIMESTAMP, TYPE_TIMESTAMP_SQL);
	 (void) new DataType(this, TYPE_NUMBER, TYPE_NUMBER_SQL);
	 //(void) new Sequence(schema(CORE_SCHEMA), SEQ_SI_PREFIXES);
	 //(void) new Table(schema(CORE_SCHEMA), TBL_SI_PREFIXES);
}