#ifndef Settings_H
#define Settings_H

#include <QtCore/QSettings>

class ConnectionData;

class Settings : public QSettings {
	Q_OBJECT;
public:
	Settings(QObject* p = 0);
	virtual ~Settings();
	void save(ConnectionData* cd_);
	void load(ConnectionData* cd_);
protected:
private:
};

#endif
