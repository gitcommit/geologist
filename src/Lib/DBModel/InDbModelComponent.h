#ifndef INDBMODELCOMPONENT_H_
#define INDBMODELCOMPONENT_H_

#include <Lib/DBModel/ModelComponent.h>

class DbModel;

class InDbModelComponent : public ModelComponent {
	Q_OBJECT
public:
	InDbModelComponent(DbModel* p = 0);
	virtual ~InDbModelComponent();
	DbModel* dbModel() const;
};

#endif /*INDBMODELCOMPONENT_H_*/
