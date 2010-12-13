#ifndef MODELCOMPONENT_H_
#define MODELCOMPONENT_H_

#include <QtCore/QObject>

class ModelComponent : public QObject {
	Q_OBJECT
public:
	ModelComponent(QObject* p = 0);
	virtual ~ModelComponent();
	virtual QString qualifiedName() const = 0;
};

#endif /*MODELCOMPONENT_H_*/
