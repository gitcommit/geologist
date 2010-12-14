#ifndef INDBMODELCOMPONENT_H_
#define INDBMODELCOMPONENT_H_

#include <Lib/DBModel/ModelComponent.h>

class DBModel;

class InDBModelComponent : public ModelComponent {
	Q_OBJECT
public:
	InDBModelComponent(DBModel* p = 0);
	virtual ~InDBModelComponent();
	DBModel* dbModel() const;
};

#endif /*INDBMODELCOMPONENT_H_*/
