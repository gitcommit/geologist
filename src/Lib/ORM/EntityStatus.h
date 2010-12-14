#ifndef ENTITYSTATUS_H_
#define ENTITYSTATUS_H_

#include <QtCore/QString>

class EntityStatus {
public:
	enum States {
		Unknown = 0,
		New,
		Dirty,
		Clean
	};
	
	EntityStatus(const EntityStatus::States& s = EntityStatus::Unknown);
	EntityStatus(const EntityStatus& other);
	virtual ~EntityStatus();
	EntityStatus::States status() const {
		return _status;
	}
	void setStatus(const EntityStatus::States& s) {
		_status = s;
	}
	QString toString() const;
private:
	EntityStatus::States _status;
};

#endif /*ENTITYSTATUS_H_*/
