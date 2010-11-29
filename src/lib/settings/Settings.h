#ifndef Settings_H
#define Settings_H

#include <QtCore/QSettings>

class Settings: public QSettings {
  Q_OBJECT
    public:
  Settings(QObject* p = 0);
  virtual ~Settings();
 protected:
 private:
};

#endif
