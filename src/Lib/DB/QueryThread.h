#ifndef QueryThread_H
#define QueryThread_H

#include <QtCore/QThread>
#include <QtCore/QList>
#include <QtCore/QMutex>
#include <QtCore/QDateTime>

#include <QtSql/QSqlRecord>
#include <QtSql/QSqlField>

#include <Lib/DB/ConnectionData.h>
#include <Lib/DB/Connection.h>

class QueryThread : public QThread {
    Q_OBJECT;

public:
    QueryThread(QObject* p = 0);
    virtual ~QueryThread();

public slots:
    virtual void open(const ConnectionData& cd);
    virtual void close();
    virtual void abort();

    void onBeginRequest();
    void onCommitRequest();
    void onRollbackRequest();
    void onSavepointRequest(const QString& name);
    void onRollbackToSavepointRequest(const QString& name);

    void onConnectionMessage(const QString& msg);
    void onConnected(const QString& msg);
    void onDisconnected();

signals:
    void beginRequest();
    void commitRequest();
    void rollbackRequest();
    void savepointRequest(const QString& name);
    void rollbackToSavepointRequest(const QString& name);

    void message(const QString& msg);
    void connected(const QString& info);
    void disconnected();
    void connectRequest(const ConnectionData& cd, const QString& connectionName);
    void disconnectRequest();
protected:
    virtual void run();

    QString connectionName() const {
        return connectionName_;
    }
private:

    void setConnectionName(const QString& n) {
        connectionName_ = n;
    }
    Connection conn_;
    QString connectionName_;
    bool abort_;
    QMutex mutex_;
};

#endif
