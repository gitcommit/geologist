#ifndef MAPPER_H_
#define MAPPER_H_

#include <QtCore/QObject>
#include <QtCore/QList>
#include <QtSql/QSqlRecord>

#include <Lib/DB/TypedQuery.h>

class Mapper : public QObject {
	Q_OBJECT
public:
	Mapper(QObject* p=0, 
			const QString& selectAllCursorName=QString::null, 
			const QString& selectAllProcedureName=QString::null);
	virtual ~Mapper();
	QString selectAllCursorName() const { return selectAllCursorName_; }
	QString selectAllProcedureName() const { return selectAllProcedureName_; }
	QString createCursorQuery() const {
		return QString("SELECT %1('%2');").arg(selectAllProcedureName()).arg(selectAllCursorName());
	}
	QString fetchAllQuery(const QString& cursorName=QString::null) const {
		QString n = cursorName;
		if (n.isEmpty()) {
			n = selectAllCursorName();
		}
		return QString("FETCH ALL IN %1;").arg(n);
	}
	QString closeCursorQuery(const QString& cursorName=QString::null) const {
		QString n = cursorName;
		if (n.isEmpty()) {
			n = selectAllCursorName();
		}
		return QString("CLOSE %1;").arg(n);
	}
	
signals:
	void queryRequest(const TypedQuery& q);
public slots:
	virtual void onQueryCompleted(const TypedQuery& q);
protected:
	virtual qlonglong nextQueryId();
	virtual qlonglong selectAllOpenId() const { return selectAllOpenId_; }
	virtual qlonglong fetchAllId() const { return fetchAllId_; }
	virtual qlonglong closeCursorId() const { return closeCursorId_; }

private:
	QString selectAllCursorName_;
	QString selectAllProcedureName_;
	
	qlonglong selectAllOpenId_;
	qlonglong fetchAllId_;
	qlonglong closeCursorId_;
};

#endif /*MAPPER_H_*/
