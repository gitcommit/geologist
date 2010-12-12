#include <InTableModelComponent.h>

#include <Table.h>

InTableModelComponent::InTableModelComponent(Table* table) :
	ModelComponent(table) {
}

InTableModelComponent::~InTableModelComponent() {
}

Table* InTableModelComponent::table() const {
	return qobject_cast<Table*>(parent());
}
