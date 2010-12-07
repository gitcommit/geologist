#ifndef TYPEDQUERY_H_
#define TYPEDQUERY_H_

#include <QtCore/QString>
#include <QtCore/QList>
#include <QtSql/QSqlRecord>

#include <Queries.h>

class TypedQuery
{
public:
	TypedQuery(const QString& sql=QString::null, const Queries::QueryId& qid=Queries::None);
	virtual ~TypedQuery();
	QString sql() const { return sql_; }
	Queries::QueryId queryId() const { return qid_; }
	QList<QSqlRecord> results() const { return results_; }
	void appendRecord(const QSqlRecord& r) { results_.append(r); }
private:
	QString sql_;
	Queries::QueryId qid_;
	QList<QSqlRecord> results_;
};

#endif /*TYPEDQUERY_H_*/
