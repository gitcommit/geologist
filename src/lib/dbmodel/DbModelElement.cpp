#include <DbModelElement.h>

DbModelElement::DbModelElement(QObject* p, const QString& name) :
	QObject(p), _name(name) {
}

DbModelElement::~DbModelElement() {
}
