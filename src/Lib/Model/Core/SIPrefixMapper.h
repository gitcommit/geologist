#ifndef SIPREFIXMAPPER_H_
#define SIPREFIXMAPPER_H_

#include <Lib/ORM/Mapper.h>
#include <Lib/Model/Core/SIPrefix.h>

class SIPrefixMapper: public Mapper
{
	Q_OBJECT
public:
	SIPrefixMapper(QObject* p);
	virtual ~SIPrefixMapper();
	void testLoad();
signals:
	void loaded(const QList<SIPrefix*>& res);
public slots:
	virtual void onQueryCompleted(const TypedQuery& q);
protected:
	SIPrefix* fromRecord(const QSqlRecord& rec);
};

#endif /*SIPREFIXMAPPER_H_*/
