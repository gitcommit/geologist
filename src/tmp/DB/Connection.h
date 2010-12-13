#ifndef CONNECTION_H
#define CONNECTION_H

#include <QtCore/QObject>
#include <QtCore/QList>
#include <QtCore/QFile>
#include <QtCore/QTextStream>
#include <QtSql/QSqlRecord>
#include <QtSql/QSqlQuery>

#include <ConnectionData.h>
#include <TypedQuery.h>

class Connection: public QObject {
	Q_OBJECT;

public:
	Connection(QObject* p=0);
	virtual ~Connection();
	void setConnectionName(const QString& n) {connectionName_ = n;}
	QString connectionName() const {return connectionName_;}

public slots:
	virtual void onConnectRequest(const ConnectionData& cd, const QString& connName);
	virtual void onDisconnectRequest();
	virtual void onExecRequest(const QList<TypedQuery>& lst);
	virtual void onExecRequest(const TypedQuery& q);
	void onBeginRequest();
	void onCommitRequest();
	void onRollbackRequest();
	void onSavepointRequest(const QString& name);
	void onRollbackToSavepointRequest(const QString& name);

signals:
	void connected(const QString& info);
	void disconnected();
	void message(const QString& msg);
	void queryCompleted(const TypedQuery& q);
	void execRequest(const TypedQuery& q);
	void begin();
	void commit();
	void rollback();
	void savepoint(const QString& name);
	void rollbackToSavepoint(const QString& name);
	void logQuery(const QString& sql);
protected slots:
	void log(const QString& sql);
protected:
	virtual QSqlQuery exec(const QString& sql);
	
private:
	ConnectionData cd_;
	QString connectionName_;
	QFile logF_;
	QTextStream logStrm_;
};

#endif // CONNECTION_H
