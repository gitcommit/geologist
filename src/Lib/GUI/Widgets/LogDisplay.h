#ifndef LOGDISPLAY_H
#define LOGDISPLAY_H

#include <QtGui/QTextEdit>

#include <Lib/DB/DatabaseError.h>

class LogDisplay: public QTextEdit {
  Q_OBJECT;
 public:
  LogDisplay(QWidget* p);
  public slots:
  void appendMessage(const QString& msg);
  void appendError(const DatabaseError& e);
};

#endif
