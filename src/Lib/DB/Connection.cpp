#include <Lib/DB/Connection.h>

#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlError>
#include <QtSql/QSqlQuery>

#include <QtCore/QVariant>
#include <QtCore/QDebug>
#include <QtCore/QDateTime>
#include <QtGui/QApplication>

#include <Lib/DB/ConnectionData.h>

Connection::Connection(QObject* p) :
	QObject(p) {
    logF_.setFileName("log.sql");
    if (!logF_.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Truncate)) {
        qFatal(tr("Could not open SQL log file %1. terminating.").arg(logF_.fileName()).toLocal8Bit());
    }
    
    logStrm_.setDevice(&logF_);
    connect(this, SIGNAL(execRequest(const TypedQuery&)), this, SLOT(onExecRequest(const TypedQuery&)));
	connect(this, SIGNAL(logQuery(const QString&)), this, SLOT(log(const QString&)));
}

Connection::~Connection() {
	onDisconnectRequest();
	logF_.close();
}

void Connection::onConnectRequest(const ConnectionData& cd,
		const QString& connName) {
	cd_ = cd;
	setConnectionName(connName);
	emit message(tr("Connecting to %1 ... as connection %2").arg(cd_.info()).arg(connectionName()));
	QSqlDatabase db = QSqlDatabase::addDatabase(cd.driver(), connectionName());
	db.setHostName(cd_.host());
	db.setPort(QVariant(cd_.port()).toInt());
	db.setDatabaseName(cd_.database());
	db.setUserName(cd_.login());
	db.setPassword(cd_.password());
	bool isConn = db.open();
	if (!isConn) {
		emit message(tr("Connection failed: %1").arg(db.lastError().text()));
		QSqlDatabase::removeDatabase(connectionName());
		emit disconnected();
		return;
	}
	emit message(tr("Connected to %1 as %2").arg(cd_.info()).arg(connectionName()));
	emit connected(cd_.info());
}

void Connection::onDisconnectRequest() {
	emit message(tr("Closing..."));
	QSqlDatabase::database(connectionName()).close();
	QSqlDatabase::removeDatabase(connectionName());
	emit message(tr("Closed."));
	emit disconnected();
}

QSqlQuery Connection::exec(const QString& sql) {
	emit message(tr("Executing query: %1").arg(sql));
	QSqlQuery q(sql, QSqlDatabase::database(connectionName()));
	if (!q.isActive()) {
		emit message(tr("ERROR: Executed Query '%1' is not active. Query Error: '%2' Database Error: '%3'.").arg(sql)
				.arg(q.lastError().text())
				.arg(QSqlDatabase::database(connectionName()).lastError().text()));
	}
	emit message(tr("Executed Query '%1' is active.").arg(sql));
	emit logQuery(q.executedQuery());
	return q;
}

void Connection::onBeginRequest() {
	emit message(tr("BEGIN requested."));
	QSqlQuery q = exec("BEGIN;");
	if (!q.isActive()) {
		qFatal("BEGIN FAILED");
	}
	emit message(tr("Transaction started."));
	emit begin();
}

void Connection::onCommitRequest() {
	emit message(tr("COMMIT requested."));
	QSqlQuery q = exec("COMMIT;");
	if (!q.isActive()) {
		qFatal("COMMIT FAILED");
	}
	emit message(tr("Transaction commited."));
	emit commit();
}

void Connection::onRollbackRequest() {
	emit message(tr("ROLLBACK requested."));
	QSqlQuery q = exec("ROLLBACK;");
	if (!q.isActive()) {
		qFatal("ROLLBACK FAILED");
	}
	emit message(tr("Transaction rolled back."));
	emit rollback();
}

void Connection::onSavepointRequest(const QString& name) {
	emit message(tr("SAVEPOINT %1 requested.").arg(name));
	QSqlQuery q = exec(QString("SAVEPOINT %1").arg(name));
	if (!q.isActive()) {
		qFatal(tr("SAVEPOINT %1 failed.").arg(name).toLocal8Bit());
	}
	emit message(tr("Savepoint %1 created.").arg(name));
	emit savepoint(name);
}

void Connection::onRollbackToSavepointRequest(const QString& name) {
	emit message(tr("ROLLBACK TO %1 requested.").arg(name));
	QSqlQuery q = exec(QString("ROLLBACK TO %1").arg(name));
	if (!q.isActive()) {
		qFatal(tr("ROLLBACK TO %1 failed.").arg(name).toLocal8Bit());
	}
	emit message(tr("Rollback to %1 completed.").arg(name));
	emit rollbackToSavepoint(name);
}

void Connection::onExecRequest(const QList<TypedQuery>& lst) {
	for (QList<TypedQuery>::const_iterator it = lst.begin(); it != lst.end(); it++) {
		emit execRequest(*it);
	}
}

void Connection::onExecRequest(const TypedQuery& q) {
	QSqlQuery qry = exec(q.sql());
	TypedQuery ret = q;
	while(qry.next()) {
		ret.appendRecord(qry.record());
	}
	emit queryCompleted(ret);
}

void Connection::log(const QString& sql) {
	logStrm_ << sql << endl;
}