#ifndef MAPPING_H_
#define MAPPING_H_

#include <QtCore/QObject>

class MappingData;

class Mapping : public QObject {
	Q_OBJECT
public:
	Mapping(QObject* p = 0);
	Mapping(const Mapping& other);
	virtual ~Mapping();
private:
	MappingData* _d;
};

#endif /*MAPPING_H_*/
