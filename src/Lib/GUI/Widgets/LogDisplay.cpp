#include <Lib/GUI/Widgets/LogDisplay.h>

#include <QtCore/QDateTime>

LogDisplay::LogDisplay(QWidget* p)
  : QTextEdit(p) {
  setAcceptRichText(false);
}

void LogDisplay::appendMessage(const QString& msg) {
  append(QString("%1: %2").arg(QDateTime::currentDateTime().toString()).arg(msg));
}
