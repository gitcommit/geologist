#ifndef SI_PREFIX_H
#define SI_PREFIX_H

#include <Lib/ORM/StandardEntity.h>

#include <QtCore/QString>
#include <QtCore/QObject>

class Mapper;
class SIPrefixData;

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
	SIPrefix(const SIPrefix& other);
	virtual ~SIPrefix();
	QString symbol() const;
	qreal factor() const;
	virtual QString toString() const {
		return QObject::tr("Name: %1, Symbol: %2, Code: %3, Factor: %4 [%5]")
		.arg(name())
		.arg(symbol())
		.arg(code())
		.arg(factor())
		.arg(descriptiveStatus());
	}
	void setSymbol(const QString& s);
	void setFactor(const qreal& r);
	Mapper* mapper() const;
signals:
	void symbolChanged(const QString& newSymbol);
	void factorChanged(const qreal& newFacto);
protected:
	SIPrefixData* siPrefixData() const;
};

#endif SI_PREFIX_H
