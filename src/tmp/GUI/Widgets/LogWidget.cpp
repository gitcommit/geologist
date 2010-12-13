#include <LogWidget.h>

#include <QtGui/QApplication>

#include <LogDisplay.h>
#include <App.h>
#include <tools.h>

LogWidget::LogWidget(QWidget* p) :
	QSplitter(p) {
	setOrientation(Qt::Vertical);
	databaseW_ = new LogDisplay(this);
	debugW_ = new LogDisplay(this);
	addWidget(databaseW_);
	addWidget(debugW_);
	connect(getApp(), SIGNAL(debugMessage(const QString&)), this, SLOT(onDebugMessage(const QString&)));
	connect(this, SIGNAL(databaseMessage(const QString&)), databaseW_, SLOT(appendMessage(const QString&)));
	connect(this, SIGNAL(debugMessage(const QString&)), debugW_, SLOT(appendMessage(const QString&)));
}

LogWidget::~LogWidget() {
}

void LogWidget::onDatabaseMessage(const QString& msg) {
	emit databaseMessage(msg);
}

void LogWidget::onDebugMessage(const QString& msg) {
	emit debugMessage(msg);
}