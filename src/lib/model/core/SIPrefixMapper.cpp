#include "SIPrefixMapper.h"

#include <QtSql/QSqlRecord>
#include <QtSql/QSqlField>

SIPrefixMapper::SIPrefixMapper(QObject* p) :
	Mapper(p, "c_all_si_prefixes", "logic.get_all_si_prefixes") {
}

SIPrefixMapper::~SIPrefixMapper() {
}

void SIPrefixMapper::testLoad() {
	emit queryRequest(TypedQuery(createCursorQuery(), selectAllOpenId()));
}

void SIPrefixMapper::onQueryCompleted(const TypedQuery& q) {
	if (q.queryId() == selectAllOpenId()) {
		emit queryRequest(TypedQuery(fetchAllQuery(), fetchAllId())); 
		return;
	}
	if (q.queryId() == fetchAllId()) {
		QList<QSqlRecord> res = q.results();
		QList<SIPrefix> ret;
		for (QList<QSqlRecord>::const_iterator it = res.begin(); it != res.end(); it++) {
			ret.append(fromRecord(*it));
		}
		emit loaded(ret);		
		emit queryRequest(TypedQuery(closeCursorQuery(), closeCursorId()));
		return;
	}
	if (q.queryId() == closeCursorId()) {
		return;
	}
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