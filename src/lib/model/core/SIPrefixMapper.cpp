#include "SIPrefixMapper.h"

#include <QtSql/QSqlRecord>
#include <QtSql/QSqlField>

SIPrefixMapper::SIPrefixMapper(QObject* p) :
	Mapper(p) {
}

SIPrefixMapper::~SIPrefixMapper() {
}

void SIPrefixMapper::onQueryCompleted(const TypedQuery& q) {
	QList<QSqlRecord> res = q.results();
	QList<SIPrefix> ret;
	for (QList<QSqlRecord>::const_iterator it = res.begin(); it != res.end(); it++) {
		ret.append(fromRecord(*it));
	}
	emit loaded(ret);
}

SIPrefix SIPrefixMapper::fromRecord(const QSqlRecord& rec) {
	SIPrefix ret;
	ret.setId(rec.field("ID").value().toInt());
	ret.setName(rec.field("NAME").value().toString());
	ret.setCode(rec.field("CODE").value().toString());
	ret.setSymbol(rec.field("SYMBOL").value().toString());
	ret.setFactor(rec.field("FACTOR").value().toDouble());
	ret.setDescription(rec.field("DESCRIPTION").value().toString());
	return ret;
}