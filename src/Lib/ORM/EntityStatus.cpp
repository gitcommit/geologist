#include <Lib/ORM/EntityStatus.h>

#include <QtCore/QObject>

EntityStatus::EntityStatus(const EntityStatus::States& s) :
	_status(s) {
}

EntityStatus::~EntityStatus() {
}

QString EntityStatus::toString() const {
	switch(status()) {
	case(EntityStatus::Unknown): return QObject::tr("Unknown");
	case(EntityStatus::New): return QObject::tr("New");
	case(EntityStatus::Dirty): return QObject::tr("Dirty");
	case(EntityStatus::Clean): return QObject::tr("Clean");
	default: return QObject::tr("Unknown Entity States (Programming Error).");
	}
}