#include <LogDisplay.h>

LogDisplay::LogDisplay(QWidget* p)
  : QTextEdit(p) {
  setAcceptRichText(false);
}

void LogDisplay::appendMessage(const QString& msg) {
  append(msg);
}
