#ifndef DATABASECONNECTIONDIALOG_H_
#define DATABASECONNECTIONDIALOG_H_

#include <Dialog.h>

class QDialogButtonBox;

class SmartGroupBox;
class LineEdit;
class PasswordEdit;

class ConnectionData;

class DatabaseConnectionDialog: public Dialog
{
	Q_OBJECT
public:
	DatabaseConnectionDialog(QWidget* p, ConnectionData* cd);
	virtual ~DatabaseConnectionDialog();
protected:
	virtual void setupContentWidget();
protected slots:
	virtual void onDriverChanged(const QString& d);
	virtual void onHostChanged(const QString& h);
	virtual void onPortChanged(const QString& p);
	virtual void onDatabaseChanged(const QString& d);
	virtual void onLoginChanged(const QString& l);
	virtual void onPasswordChanged(const QString& p);
	
private:
	SmartGroupBox* contentW_;
	QDialogButtonBox* buttonsW_;
	ConnectionData* cd_;
	
	LineEdit* driverW_;
	LineEdit* hostW_;
	LineEdit* portW_;
	LineEdit* databaseW_;
	LineEdit* loginW_;
	PasswordEdit* passwordW_;
};

#endif /*DATABASECONNECTIONDIALOG_H_*/
