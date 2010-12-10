#include <DbModelElement.h>

DbModelElement::DbModelElement(QObject* p, const QString& name) :
	QObject(p), _name(name) {
	setObjectName(name);
}

DbModelElement::~DbModelElement() {
}
