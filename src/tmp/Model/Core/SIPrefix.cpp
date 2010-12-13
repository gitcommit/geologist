#include <SIPrefix.h>

#include <App.h>

#include <SiPrefixMapper.h>
#include <private/SIPrefixData.h>

SIPrefix::SIPrefix(QObject* p, const qulonglong& id, const QString& name,
		const QString& code, const QString& symbol, const qreal& factor,
		const QString& description) :
	StandardEntity(p, id, name, code, description) {
	setData(new SIPrefixData(id, name, code, symbol, factor, description));

	connect(this, SIGNAL(symbolChanged(const QString&)), this, SIGNAL(dataChanged()));
	connect(this, SIGNAL(factorChanged(const qreal&)), this, SIGNAL(dataChanged()));
}

SIPrefix::SIPrefix(const SIPrefix& other) :
	StandardEntity(other) {
}

SIPrefix::~SIPrefix() {
}

Mapper* SIPrefix::mapper() const {
	return app()->siPrefixMapper();
}

SIPrefixData* SIPrefix::siPrefixData() const {
	Q_ASSERT(hasData());
	Q_CHECK_PTR(data());
	return reinterpret_cast<SIPrefixData*>(data());
}

void SIPrefix::setSymbol(const QString& s) {
	emit symbolChanged(s);
	siPrefixData()->setSymbol(s);
}

void SIPrefix::setFactor(const qreal& f) {
	emit factorChanged(f);
	siPrefixData()->setFactor(f);
}

QString SIPrefix::symbol() const {
	return siPrefixData()->symbol();
}

qreal SIPrefix::factor() const {
	return siPrefixData()->factor();
}