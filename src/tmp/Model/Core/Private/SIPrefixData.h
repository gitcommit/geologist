#ifndef SIPREFIXDATA_H_
#define SIPREFIXDATA_H_

#include <StandardEntityData.h>

class SIPrefixData: public StandardEntityData
{
public:
	SIPrefixData(const qulonglong& id = 0,
			const QString& name = QString::null,
			const QString& code = QString::null,
			const QString& symbol = QString::null,
			const qreal& factor = 0.0,
			const QString& description = QString::null);
	SIPrefixData(const SIPrefixData& other);
	virtual ~SIPrefixData();
	
	virtual void setSymbol(const QString& s) { _symbol = s; }
	virtual void setFactor(const qreal& f) { _factor = f; }
	
	QString symbol() const { return _symbol; }
	qreal factor() const { return _factor; }
	
private:
	QString _symbol;
	qreal _factor;
};

#endif /*SIPREFIXDATA_H_*/
