#ifndef SI_PREFIX_H
#define SI_PREFIX_H

#include <Entity.h>

#include <QtCore/QString>

class SIPrefix: public Entity {
 public:
  SIPrefix(const qulonglong& id = 0,
	   const QString& name = QString::null,
	   const QString& code = QString::null,
	   const QString& symbol = QString::null,
	   const qreal& factor = 0.0,
	   const QString& description = QString::null);
  SIPrefix(const SIPrefix& other);
  virtual ~SIPrefix();

  qulonglong id() const { return id_; }
  QString name() const { return name_; }
  QString code() const { return code_; }
  QString symbol() const { return symbol_; }
  qreal factor() const { return factor_; }
  QString description() const { return description_; }

 private:
  qulonglong id_;
  QString name_;
  QString code_;
  QString symbol_;
  qreal factor_;
  QString description_;
};

#endif SI_PREFIX_H
