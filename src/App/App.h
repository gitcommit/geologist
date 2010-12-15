#ifndef App_H
#define App_H

#include <QtGui/QApplication>
#include <QtCore/QString>

#include <Lib/DBModel/DBModel.h>
#include <Lib/DB/ConnectionData.h>

#include <Lib/DB/QueryThread.h>

#include <Lib/Model/Core/SIPrefix.h>

class SIPrefixMapper;
class Mapping;

class App : public QApplication {
    Q_OBJECT;
public:
    App(int argc, char** argv);
    virtual ~App();
    void init();

    Mapping* siPrefixMapping() const {
        return _siPrefixMapping;
    }

    qlonglong nextQueryId() {
        _lastQueryId++;
        return _lastQueryId;
    }

signals:
    void beginRequest();
    void commitRequest();
    void rollbackRequest();
    void savepointRequest(const QString& name);
    void rollbackToSavepointRequest(const QString& name);
    void connectRequest(const ConnectionData& cd);
    void disconnectRequest();
    void databaseOpened(const QString& info);
    void databaseClosed();
    void databaseMessage(const QString& msg);
    void debugMessage(const QString& msg);
public slots:
    virtual void debug(const QString& msg);
    virtual void onOpenDB();
    virtual void onCloseDB();
    void onDatabaseMessage(const QString& msg);
    void onConnected(const QString& msg);
    void onDisconnected();
    void onSIPrefixesLoaded(const QList<SIPrefix*>& lst);
protected:
    virtual void registerMetatypes();
private:
    QueryThread _dbThread;

    ConnectionData _cd;
    Mapping* _siPrefixMapping;
    qlonglong _lastQueryId;
    DBModel _dbModel;
};

#endif
