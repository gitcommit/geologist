#include "SIPrefixMapper.h"

#include <QtGui/QApplication>
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
		QList<SIPrefix*> ret;
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

SIPrefix* SIPrefixMapper::fromRecord(const QSqlRecord& rec) {
	SIPrefix* ret = new SIPrefix(QApplication::instance());
	ret->setProperty("id", rec.field("ID").value());
	ret->setProperty("name", rec.field("NAME").value());
	ret->setProperty("code", rec.field("CODE").value());
	ret->setProperty("symbol", rec.field("SYMBOL").value());
	ret->setProperty("factor", rec.field("FACTOR").value());
	ret->setProperty("description", rec.field("DESCRIPTION").value());
	ret->setStatus(Entity::Clean);
	return ret;
}