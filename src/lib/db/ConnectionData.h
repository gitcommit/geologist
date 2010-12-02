#ifndef CONNECTIONDATA_H_
#define CONNECTIONDATA_H_

#include <QtCore/QString>
#include <QtCore/QMetaObject>

class ConnectionData {
public:
	ConnectionData(const QString& driver = QString::null,
			const QString& host = QString::null,
			const QString& port = QString::null,
			const QString& db = QString::null,
			const QString& login = QString::null,
			const QString& password = QString::null, const bool& drop = false,
			const bool& create = false, const bool& debug = false);
	ConnectionData(const ConnectionData& other);
	virtual ~ConnectionData();
	QString driver() const {
		return driver_;
	}
	QString host() const {
		return host_;
	}
	QString port() const {
		return port_;
	}
	QString database() const {
		return db_;
	}
	QString login() const {
		return login_;
	}
	QString password() const {
		return pass_;
	}
	bool drop() const {
		return drop_;
	}
	bool create() const {
		return create_;
	}
	bool debug() const {
		return debug_;
	}
	QString info() const {
		return QString("%1://%2@%3:%4/%5").arg(driver()).arg(login()).arg(host()).arg(port()).arg(database());
	}

	void setDriver(const QString& d) {
		driver_ = d;
	}
	void setHost(const QString& h) {
		host_ = h;
	}
	void setPort(const QString& p) {
		port_ = p;
	}
	void setDatabase(const QString& d) {
		db_ = d;
	}
	void setLogin(const QString& l) {
		login_ = l;
	}
	void setPassword(const QString& p) {
		pass_ = p;
	}
	void setDrop(const bool& d) {
		drop_ = d;
	}
	void setCreate(const bool& c) {
		create_ = c;
	}
	void setDebug(const bool& d) {
		debug_ = d;
	}
private:
	QString driver_;
	QString host_;
	QString port_;
	QString db_;
	QString login_;
	QString pass_;
	bool drop_;
	bool create_;
	bool debug_;
};

#endif /*CONNECTIONDATA_H_*/
