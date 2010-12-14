#include <Lib/DBModel/Private/Base.h>

Base::Base(const QString& name) :
	_name(name) {
}

Base::Base(const Base& other) :
	QSharedData(other), _name(other.name()) {
}

Base::~Base()
{}
