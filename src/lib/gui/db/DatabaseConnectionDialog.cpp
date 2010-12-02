#include "DatabaseConnectionDialog.h"

#include <QtGui/QLayout>
#include <QtGui/QDialogButtonBox>

#include <SmartGroupBox.h>
#include <LineEdit.h>
#include <PasswordEdit.h>

#include <ConnectionData.h>

DatabaseConnectionDialog::DatabaseConnectionDialog(QWidget* p,
		ConnectionData* cd) :
	Dialog(p), cd_(cd) {
	contentW_ = new SmartGroupBox(this, tr("Database Connection"));
	buttonsW_ = new QDialogButtonBox(QDialogButtonBox::Ok|QDialogButtonBox::Cancel, 
			Qt::Horizontal, 
			this);
	setupContentWidget();
	addWidget(contentW_);
	addWidget(buttonsW_);
	connect(buttonsW_, SIGNAL(accepted()), this, SLOT(accept()));
	connect(buttonsW_, SIGNAL(rejected()), this, SLOT(reject()));
}

DatabaseConnectionDialog::~DatabaseConnectionDialog() {
}

void DatabaseConnectionDialog::setupContentWidget() {
	driverW_ = new LineEdit(contentW_, tr("&Driver"), cd_->driver());
	hostW_ = new LineEdit(contentW_, tr("&Host"), cd_->host());
	portW_ = new LineEdit(contentW_, tr("&Port"), cd_->port());
	databaseW_ = new LineEdit(contentW_, tr("D&atabase"), cd_->database());
	loginW_ = new LineEdit(contentW_, tr("&Login"), cd_->login());
	passwordW_ = new PasswordEdit(contentW_, tr("Pa&ssword"), cd_->password());
	connect(driverW_, SIGNAL(valueChanged(const QString&)), this, SLOT(onDriverChanged(const QString&)));
	connect(hostW_, SIGNAL(valueChanged(const QString&)), this, SLOT(onHostChanged(const QString&)));
	connect(portW_, SIGNAL(valueChanged(const QString&)), this, SLOT(onPortChanged(const QString&)));
	connect(databaseW_, SIGNAL(valueChanged(const QString&)), this, SLOT(onDatabaseChanged(const QString&)));
	connect(loginW_, SIGNAL(valueChanged(const QString&)), this, SLOT(onLoginChanged(const QString&)));
	connect(passwordW_, SIGNAL(valueChanged(const QString&)), this, SLOT(onPasswordChanged(const QString&)));
}

void DatabaseConnectionDialog::onDriverChanged(const QString& d) {
	cd_->setDriver(d);
}

void DatabaseConnectionDialog::onHostChanged(const QString& h) {
	cd_->setHost(h);
}

void DatabaseConnectionDialog::onPortChanged(const QString& p) {
	cd_->setPort(p);
}

void DatabaseConnectionDialog::onDatabaseChanged(const QString& d) {
	cd_->setDatabase(d);
}

void DatabaseConnectionDialog::onLoginChanged(const QString& l) {
	cd_->setLogin(l);
}
	
void DatabaseConnectionDialog::onPasswordChanged(const QString& p) {
	cd_->setPassword(p);
}
	
