#include <Lib/DBModel/InTableModelComponent.h>

#include <Lib/DBModel/Table.h>

InTableModelComponent::InTableModelComponent(Table* table) :
	ModelComponent(table) {
}

InTableModelComponent::~InTableModelComponent() {
}

Table* InTableModelComponent::table() const {
	return qobject_cast<Table*>(parent());
}
