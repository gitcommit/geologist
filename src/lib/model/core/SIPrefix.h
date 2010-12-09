#ifndef SI_PREFIX_H
#define SI_PREFIX_H

#include <IdentifiedEntity.h>

#include <QtCore/QString>
#include <QtCore/QObject>

class SIPrefix : public IdentifiedEntity {
	Q_OBJECT
	Q_PROPERTY(QString name READ name WRITE setName)
	Q_PROPERTY(QString code READ code WRITE setCode)
	Q_PROPERTY(QString symbol READ symbol WRITE setSymbol)
	Q_PROPERTY(QString description READ description WRITE setDescription)
public:
	SIPrefix(QObject* p=0,
			const qulonglong& id = 0, const QString& name = QString::null,
			const QString& code = QString::null,
			const QString& symbol = QString::null, const qreal& factor = 0.0,
			const QString& description = QString::null);
	virtual ~SIPrefix();
	QString name() const {
		return name_;
	}
	QString code() const {
		return code_;
	}
	QString symbol() const {
		return symbol_;
	}
	qreal factor() const {
		return factor_;
	}
	QString description() const {
		return description_;
	}
	QString toString() const {
		return QObject::tr("Name: %1, Symbol: %2, Code: %3, Factor: %4")
		.arg(name())
		.arg(symbol())
		.arg(code())
		.arg(factor());
	}
	void setName(const QString& n) {
		name_ = n;
	}
	void setCode(const QString& c) {
		code_ = c;
	}
	void setSymbol(const QString& s) {
		symbol_ = s;
	}
	void setFactor(const qreal& r) {
		factor_ = r;
	}
	void setDescription(const QString& d) {
		description_ = d;
	}
private:
	SIPrefix(const SIPrefix& other);

	QString name_;
	QString code_;
	QString symbol_;
	qreal factor_;
	QString description_;
};

#endif SI_PREFIX_H
