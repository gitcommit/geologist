#include <SIPrefix.h>

SIPrefix::SIPrefix(const qulonglong& id,
		   const QString& name,
		   const QString& code,
		   const QString& symbol,
		   const qreal& factor,
		   const QString& description)
  : Entity()
  {}

SIPrefix::SIPrefix(const SIPrefix& o)
  : Entity(o) {
  id_ = o.id();
  name_ = o.name();
  code_ = o.code();
  symbol_ = o.symbol();
  factor_ = o.factor();
  description_ = o.description();
}

SIPrefix::~SIPrefix()
{}

