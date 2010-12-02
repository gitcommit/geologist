#ifndef LOGWIDGET_H
#define LOGWIDGET_H

#include <QtGui/QSplitter>

class LogDisplay;

class LogWidget: public QSplitter
{
  Q_OBJECT;
 public:
  LogWidget(QWidget* p);
  virtual ~LogWidget();
  public slots:
  void onDatabaseMessage(const QString& msg);
 signals:
  void databaseMessage(const QString& msg);

 private:
  LogDisplay* databaseW_;
};

#endif
