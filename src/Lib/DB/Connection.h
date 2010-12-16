#ifndef CONNECTION_H
#define CONNECTION_H

#include <QtCore/QObject>
#include <QtCore/QList>
#include <QtCore/QFile>
#include <QtCore/QTextStream>
#include <QtSql/QSqlRecord>
#include <QtSql/QSqlQuery>

#include <Lib/DB/ConnectionData.h>
#include <Lib/DB/DatabaseError.h>

#include <Lib/ORM/DeclareSelectCursorQuery.h>
#include <Lib/ORM/FetchAllInCursorQuery.h>
#include <Lib/ORM/CloseCursorQuery.h>

class Connection : public QObject {
    Q_OBJECT;

public:
    Connection(QObject* p = 0);
    virtual ~Connection();

    void setConnectionName(const QString& n) {
        connectionName_ = n;
    }

    QString connectionName() const {
        return connectionName_;
    }

public slots:
    virtual void onConnectRequest(const ConnectionData& cd, const QString& connName);
    virtual void onDisconnectRequest();
    void onBeginRequest();
    void onCommitRequest();
    void onRollbackRequest();
    void onSavepointRequest(const QString& name);
    void onRollbackToSavepointRequest(const QString& name);
    void onQueryRequest(const DeclareSelectCursorQuery& q);
    void onQueryRequest(const FetchAllInCursorQuery& q);
    void onQueryRequest(const CloseCursorQuery& q);

signals:
    void connected(const QString& info);
    void disconnected();
    void message(const QString& msg);
    void begin();
    void commit();
    void rollback();
    void savepoint(const QString& name);
    void rollbackToSavepoint(const QString& name);
    
    void queryCompleted(const DeclareSelectCursorQuery& q);
    void queryCompleted(const FetchAllInCursorQuery& q);
    void queryCompleted(const CloseCursorQuery& q);
    
    void logQuery(const QString& sql);
    void error(const DatabaseError& e);
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
