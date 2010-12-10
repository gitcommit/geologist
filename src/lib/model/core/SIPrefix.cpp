#include <SIPrefix.h>

SIPrefix::SIPrefix(QObject* p, const qulonglong& id, const QString& name,
		const QString& code, const QString& symbol, const qreal& factor,
		const QString& description) :
	StandardEntity(p, id, name, code, description),
	_symbol(symbol),
	_factor(factor) {
}

SIPrefix::SIPrefix(const SIPrefix& o) {
}

SIPrefix::~SIPrefix() {
}

