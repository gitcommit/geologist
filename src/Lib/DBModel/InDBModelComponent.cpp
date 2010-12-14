#include <Lib/DBModel/InDBModelComponent.h>

#include <Lib/DBModel/DBModel.h>

InDBModelComponent::InDBModelComponent(DBModel* m) :
	ModelComponent(m) {
}

InDBModelComponent::~InDBModelComponent() {
}

DBModel* InDBModelComponent::dbModel() const {
	return qobject_cast<DBModel*>(parent());
}
