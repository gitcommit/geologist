#ifndef LOGDISPLAY_H
#define LOGDISPLAY_H

#include <QtGui/QTextEdit>

class LogDisplay: public QTextEdit {
  Q_OBJECT
    public:
  LogDisplay(QWidget* p);
  public slots:
  void appendMessage(const QString& msg);
};

#endif
