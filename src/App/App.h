#ifndef App_H
#define App_H

#include <QtGui/QApplication>
#include <QtCore/QString>

#include <Lib/DBModel/DBModel.h>
#include <Lib/DB/ConnectionData.h>

#include <Lib/DB/QueryThread.h>
#include <Lib/DB/TypedQuery.h>

#include <Lib/Model/Core/SIPrefix.h>
 
class SIPrefixMapper;
class Mapping;

class App: public QApplication {
	Q_OBJECT;
 public:
	App(int argc, char** argv);
	virtual ~App();
	void init();
	SIPrefixMapper* siPrefixMapper() const {
		return _siPrefixMapper;
	}
	Mapping* siPrefixMapping() const {
		return _siPrefixMapping;
	}
	qlonglong nextQueryId() { lastQueryId_++; return lastQueryId_; }
	
 signals:
 	void queryRequest(const TypedQuery& q);
 	void queryRequest(const QList<TypedQuery>& qlst);
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
	QueryThread dbThread_;

	ConnectionData cd_;
	SIPrefixMapper* _siPrefixMapper;
	Mapping* _siPrefixMapping;
	qlonglong lastQueryId_;
	qlonglong currentUserQueryId_;
	DBModel _dbModel;
};

#endif
