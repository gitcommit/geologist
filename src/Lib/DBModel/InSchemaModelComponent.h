#ifndef INSCHEMAMODELCOMPONENT_H_
#define INSCHEMAMODELCOMPONENT_H_

#include <Lib/DBModel/ModelComponent.h>

class Schema;

class InSchemaModelComponent : public ModelComponent {
	Q_OBJECT
public:
	InSchemaModelComponent(Schema* schema = 0);
	virtual ~InSchemaModelComponent();
	Schema* schema() const;
};

#endif /*INSCHEMAMODELCOMPONENT_H_*/
