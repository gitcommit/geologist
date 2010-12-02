#include <LogWidget.h>

#include <LogDisplay.h>

LogWidget::LogWidget(QWidget* p)
  : QSplitter(p)
{
  setOrientation(Qt::Horizontal);
  databaseW_ = new LogDisplay(this);
  addWidget(databaseW_);
  connect(this, SIGNAL(databaseMessage(const QString&)), databaseW_, SLOT(appendMessage(const QString&)));
}

LogWidget::~LogWidget() {
}

void LogWidget::onDatabaseMessage(const QString& msg) {
  emit databaseMessage(msg);
}
