#ifndef SI_PREFIX_H
#define SI_PREFIX_H

#include <StandardEntity.h>

#include <QtCore/QString>
#include <QtCore/QObject>

class SIPrefix : public StandardEntity {
	Q_OBJECT
	Q_PROPERTY(QString symbol READ symbol WRITE setSymbol NOTIFY symbolChanged)
	Q_PROPERTY(qreal factor READ factor WRITE setFactor NOTIFY factorChanged)
public:
	SIPrefix(QObject* p=0,
			const qulonglong& id = 0, const QString& name = QString::null,
			const QString& code = QString::null,
			const QString& symbol = QString::null, const qreal& factor = 0.0,
			const QString& description = QString::null);
	virtual ~SIPrefix();
	QString symbol() const {
		return _symbol;
	}
	qreal factor() const {
		return _factor;
	}
	QString toString() const {
		return QObject::tr("Name: %1, Symbol: %2, Code: %3, Factor: %4 [%5]")
		.arg(name())
		.arg(symbol())
		.arg(code())
		.arg(factor())
		.arg(descriptiveStatus());
	}
	void setSymbol(const QString& s) {
		_symbol = s;
		emit symbolChanged();
	}
	void setFactor(const qreal& r) {
		_factor = r;
		emit factorChanged();
	}
signals:
	void symbolChanged();
	void factorChanged();
private:
	SIPrefix(const SIPrefix& other);

	QString _symbol;
	qreal _factor;
};

#endif SI_PREFIX_H
