#ifndef App_H
#define App_H

#include <QtGui/QApplication>
#include <QtCore/QString>

#include <DbModel.h>

#include <ConnectionData.h>

#include <QueryThread.h>
#include <TypedQuery.h>

#include <SIPrefix.h>
 
class SIPrefixMapper;

class App: public QApplication {
	Q_OBJECT;
 public:
	App(int argc, char** argv);
	virtual ~App();
	void init();
	SIPrefixMapper* siPrefixMapper() const {
		return _siPrefixMapper;
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
  	virtual void onOpenDb();
  	virtual void onCloseDb();
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
	qlonglong lastQueryId_;
	qlonglong currentUserQueryId_;
	DbModel _dbModel;
};

#endif
