#ifndef SIPREFIXMAPPER_H_
#define SIPREFIXMAPPER_H_

#include <Mapper.h>
#include <SIPrefix.h>

class SIPrefixMapper: public Mapper
{
	Q_OBJECT
public:
	SIPrefixMapper(QObject* p);
	virtual ~SIPrefixMapper();
signals:
	void loaded(const QList<SIPrefix>& res);
public slots:
	virtual void onQueryCompleted(const QList<QSqlRecord>& res, const Queries::QueryId& qid);
protected:
	SIPrefix fromRecord(const QSqlRecord& rec);
};

#endif /*SIPREFIXMAPPER_H_*/
