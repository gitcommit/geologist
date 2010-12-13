#include <Mapping.h>

#include <private/MappingData.h>

Mapping::Mapping(QObject* p) :
	QObject(p), _d(0) {
	_d = new MappingData();
}

Mapping::Mapping(const Mapping& other) :
	_d(0) {
}

Mapping::~Mapping() {
}
