#include <Lib/Model/Core/SIPrefix.h>

#include <App/App.h>

#include <Lib/Tools/tools.h>
#include <Lib/Model/Core/Private/SIPrefixData.h>

SIPrefix::SIPrefix(QObject* p, const qulonglong& id, const QString& name,
        const QString& code, const QString& symbol, const qreal& factor,
        const QString& description)
: StandardEntity(p, id, name, code, description) {
    _d = new SIPrefixData(id, name, code, symbol, factor, description);

    connect(this, SIGNAL(symbolChanged(const QString&)), this, SIGNAL(dataChanged()));
    connect(this, SIGNAL(factorChanged(
            const qreal&)), this, SIGNAL(dataChanged()));
}

SIPrefix::SIPrefix(const SIPrefix& other)
: StandardEntity(other), _d(other._d) {
}

SIPrefix::~SIPrefix() {
}

void SIPrefix::setSymbol(const QString& s) {
    emit symbolChanged(s);
    _d->setSymbol(s);
}

void SIPrefix::setId(const qulonglong& id) {
    emit idChanged(id);
    _d->setId(id);
}

void SIPrefix::setName(const QString& name) {
    emit nameChanged(name);
    _d->setName(name);
}

void SIPrefix::setCode(const QString& code) {
    emit codeChanged(code);
    _d->setCode(code);
}

void SIPrefix::setFactor(const qreal& f) {
    emit factorChanged(f);
    _d->setFactor(f);
}

void SIPrefix::setDescription(const QString& d) {
    emit descriptionChanged(d);
    _d->setDescription(d);
}

qulonglong SIPrefix::id() const {
    return _d->id();
}

QString SIPrefix::name() const {
    return _d->name();
}

QString SIPrefix::code() const {
    return _d->code();
}

QString SIPrefix::symbol() const {
    return _d->symbol();
}

qreal SIPrefix::factor() const {
    return _d->factor();
}

QString SIPrefix::description() const {
    return _d->description();
}

bool SIPrefix::hasId() const {
    return _d->hasId();
}

QString SIPrefix::toString() const {
    return tr("SI Prefix '%1' with factor %2 and symbol '%3' [%4]").arg(name()).arg(factor()).arg(symbol()).arg(code());
}