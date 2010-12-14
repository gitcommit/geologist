#ifndef INTABLEMODELCOMPONENT_H_
#define INTABLEMODELCOMPONENT_H_

#include <Lib/DBModel/ModelComponent.h>

class Table;

class InTableModelComponent : public ModelComponent {
	Q_OBJECT
public:
	InTableModelComponent(Table* table = 0);
	virtual ~InTableModelComponent();
	Table* table() const;
};

#endif /*INTABLEMODELCOMPONENT_H_*/
