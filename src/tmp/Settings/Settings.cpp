#include <Settings.h>

#include <ConnectionData.h>

Settings::Settings(QObject* p)
  : QSettings(p)
{}

Settings::~Settings()
{}

void Settings::save(ConnectionData* cd) {
	setValue("ConnectionData/driver", cd->driver());
	setValue("ConnectionData/host", cd->host());
	setValue("ConnectionData/port", cd->port());
	setValue("ConnectionData/database", cd->database());
	setValue("ConnectionData/login", cd->login());
	setValue("ConnectionData/drop", cd->drop());
	setValue("ConnectionData/create", cd->create());
	setValue("ConnectionData/debug", cd->debug());
}

void Settings::load(ConnectionData* cd) {
	cd->setDriver(value("ConnectionData/driver", "QPSQL7").toString());
	cd->setHost(value("ConnectionData/host", "localhost").toString());
	cd->setPort(value("ConnectionData/port", "5433").toString());
	cd->setDatabase(value("ConnectionData/database", "test").toString());
	cd->setLogin(value("ConnectionData/login", "jolo").toString());
	cd->setPassword(QString::null);
	cd->setDrop(value("ConnectionData/drop", false).toBool());
	cd->setCreate(value("ConnectionData/create", false).toBool());
	cd->setDebug(value("ConnectionData/debug", false).toBool());
}