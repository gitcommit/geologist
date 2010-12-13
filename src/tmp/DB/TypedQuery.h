#ifndef TYPEDQUERY_H_
#define TYPEDQUERY_H_

#include <QtCore/QString>
#include <QtCore/QList>
#include <QtSql/QSqlRecord>

class TypedQuery
{
public:
	TypedQuery(const QString& sql=QString::null, const qlonglong& qid=0);
	virtual ~TypedQuery();
	QString sql() const { return sql_; }
	qlonglong queryId() const { return qid_; }
	QList<QSqlRecord> results() const { return results_; }
	void appendRecord(const QSqlRecord& r) { results_.append(r); }
private:
	QString sql_;
	qlonglong qid_;
	QList<QSqlRecord> results_;
};

#endif /*TYPEDQUERY_H_*/
