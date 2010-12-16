#include <App.h>

#include <QtCore/QDebug>
#include <QtCore/QMetaType>
#include <QtCore/QDateTime>
#include <QtCore/QString>
#include <QtCore/QList>
#include <QtSql/QSqlRecord>

#include <App/config.h>

#include <Lib/DB/QueryThread.h>
#include <Lib/DB/ConnectionData.h>

#include <Lib/GUI/DB/DatabaseConnectionDialog.h>

#include <Lib/Model/Core/SIPrefix.h>

#include <Lib/ORM/Entity.h>

#include <Lib/Settings/Settings.h>
#include <Lib/DBModel/DBModel.h>
#include <Lib/DBModel/Schema.h>
#include <Lib/DBModel/Table.h>

#include <Lib/ORM/Mapping.h>
#include <Lib/Managers/Core/SIPrefixManager.h>

Q_DECLARE_METATYPE(ConnectionData)
Q_DECLARE_METATYPE(QDateTime)
Q_DECLARE_METATYPE(QString)
Q_DECLARE_METATYPE(QSqlRecord)
Q_DECLARE_METATYPE(QList<QSqlRecord>)

App::App(int argc, char** argv)
: QApplication(argc, argv), _lastQueryId(0), _dbModel(0), _siPrefixManager(0) {
    setApplicationVersion(APP_VERSION);
    setApplicationName(APP_NAME);
    setOrganizationDomain(ORG_DOMAIN);
    setOrganizationName(ORG_NAME);
    registerMetatypes();
    init();
}

void App::registerMetatypes() {
    qRegisterMetaType<ConnectionData > ("ConnectionData");
    qRegisterMetaType<QList<QSqlRecord> >("QList<QSqlRecord>");
    qRegisterMetaType<QDateTime > ("QDateTime");
    qRegisterMetaType<QString > ("QString>");
    qRegisterMetaType<QList<QSqlRecord> >("QList<QSqlRecord>");
}

void App::init() {
    Settings s(this);
    s.load(&_cd);
    _dbModel.setName(DB_NAME);
    _dbModel.loadFromFile(DB_CONFIG_FILE);
    _siPrefixMapping = new Mapping(this, _dbModel.schema("core")->table("si_prefixes"));
    _siPrefixManager = new SIPrefixManager(this);

    connect(&_dbThread, SIGNAL(message(const QString&)), this, SLOT(onDatabaseMessage(const QString&)));
    connect(&_dbThread, SIGNAL(connected(const QString&)), this, SLOT(onConnected(const QString&)));
    connect(&_dbThread, SIGNAL(disconnected()), this, SLOT(onDisconnected()));
    connect(&_dbThread, SIGNAL(connected(const QString&)), _siPrefixManager, SLOT(loadAll()));
    
    connect(this, SIGNAL(connectRequest(const ConnectionData&)), &_dbThread, SLOT(open(const ConnectionData&)));
    connect(this, SIGNAL(disconnectRequest()), &_dbThread, SLOT(close()));
    connect(this, SIGNAL(beginRequest()), &_dbThread, SLOT(onBeginRequest()));
    connect(this, SIGNAL(commitRequest()), &_dbThread, SLOT(onCommitRequest()));
    connect(this, SIGNAL(rollbackRequest()), &_dbThread, SLOT(onRollbackRequest()));
    connect(this, SIGNAL(savepointRequest(const QString&)), &_dbThread, SLOT(onSavepointRequest(const QString&)));
    connect(this, SIGNAL(rollbackToSavepointRequest(const QString&)), &_dbThread, SLOT(onRollbackToSavepointRequest(const QString&)));
}

App::~App() {
    _dbThread.quit();
    _dbThread.wait();
}

void App::debug(const QString& msg) {
    emit debugMessage(tr("Debug: %1").arg(msg));
}

void App::onOpenDB() {
    Settings s(this);
    DatabaseConnectionDialog* d = new DatabaseConnectionDialog(activeWindow(), &_cd);
    if (QDialog::Accepted != d->exec()) {
        s.load(&_cd);
        return;
    }
    s.save(&_cd);
    emit connectRequest(_cd);
}

void App::onCloseDB() {
    emit disconnectRequest();
}

void App::onDatabaseMessage(const QString& msg) {
    emit databaseMessage(msg);
}

void App::onConnected(const QString& msg) {
    emit databaseMessage(tr("Connected: %1").arg(msg));
    emit databaseOpened(msg);
    /*currentUserQueryId_ = nextQueryId();
    emit beginRequest();
    emit queryRequest(TypedQuery("SELECT CURRENT_USER AS CURRENT_USER;", currentUserQueryId_));
     */
    emit debugMessage(tr("\n-- CREATE DATABASE script --\n%1\n-- end of CREATE DATABASE script.\n")
            .arg(_dbModel.create().join("\n")));
    emit beginRequest();
}

void App::onDisconnected() {
    emit databaseMessage(tr("Disconnected."));
    emit databaseClosed();
}

void App::onSIPrefixesLoaded(const QList<SIPrefix*>& lst) {
    emit debugMessage(tr("App::onSIPrefixesLoaded(...)"));
    for (QList<SIPrefix*>::const_iterator it = lst.begin(); it != lst.end(); it++) {
        emit debugMessage(tr("Loaded SI Prefix: %1").arg((*it)->toString()));
    }
}
