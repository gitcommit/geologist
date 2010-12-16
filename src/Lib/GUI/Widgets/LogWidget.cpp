#include <Lib/GUI/Widgets/LogWidget.h>

#include <QtGui/QApplication>

#include <Lib/GUI/Widgets/LogDisplay.h>
#include <App/App.h>
#include <Lib/Tools/tools.h>
#include <Lib/DB/DatabaseError.h>

LogWidget::LogWidget(QWidget* p) :
	QSplitter(p) {
	setOrientation(Qt::Vertical);
	databaseW_ = new LogDisplay(this);
	debugW_ = new LogDisplay(this);
	addWidget(databaseW_);
	addWidget(debugW_);
	connect(getApp(), SIGNAL(debugMessage(const QString&)), this, SLOT(onDebugMessage(const QString&)));
	connect(this, SIGNAL(databaseMessage(const QString&)), databaseW_, SLOT(appendMessage(const QString&)));
        connect(getApp()->databaseThread(), SIGNAL(error(const DatabaseError&)), databaseW_, SLOT(appendError(const DatabaseError&)));
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