#include <InDbModelComponent.h>

#include <DbModel.h>

InDbModelComponent::InDbModelComponent(DbModel* m) :
	ModelComponent(m) {
}

InDbModelComponent::~InDbModelComponent() {
}

DbModel* InDbModelComponent::dbModel() const {
	return qobject_cast<DbModel*>(parent());
}