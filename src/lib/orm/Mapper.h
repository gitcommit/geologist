#ifndef MAPPER_H_
#define MAPPER_H_

#include <QtCore/QObject>
#include <QtCore/QList>
#include <QtSql/QSqlRecord>

#include <TypedQuery.h>

class Mapper : public QObject {
	Q_OBJECT
public:
	Mapper(QObject* p=0);
	virtual ~Mapper();
public slots:
	virtual void onQueryCompleted(const TypedQuery& q);
protected:
	virtual qlonglong nextQueryId();
	qlonglong selectAllOpenCursorQueryId_;
	qlonglong selectAllFetchAllQueryId_;
	qlonglong selectAllCloseCursorQueryId_;
};

#endif /*MAPPER_H_*/
