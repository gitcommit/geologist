#include <Lib/Model/Core/Private/SIPrefixData.h>

SIPrefixData::SIPrefixData(const qulonglong& id, const QString& name,
		const QString& code, const QString& symbol, const qreal& factor,
		const QString& description) :
	StandardEntityData(id, name, code, description), _symbol(symbol),
			_factor(factor) {
}

SIPrefixData::SIPrefixData(const SIPrefixData& other) :
	StandardEntityData(other), _symbol(other._symbol), _factor(other._factor) {
}

SIPrefixData::~SIPrefixData() {
}
