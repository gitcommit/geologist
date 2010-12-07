#ifndef MAPPER_H_
#define MAPPER_H_

#include <QtCore/QObject>
#include <QtCore/QList>
#include <QtSql/QSqlRecord>

#include <Queries.h>

class Mapper : public QObject {
	Q_OBJECT
public:
	Mapper(QObject* p=0);
	virtual ~Mapper();
public slots:
	virtual void onQueryCompleted(const QList<QSqlRecord>& res, const Queries::QueryId& qid);
};

#endif /*MAPPER_H_*/
