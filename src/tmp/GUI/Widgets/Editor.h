#ifndef EDITOR_H_
#define EDITOR_H_

#include <SmartGroupBox.h>

class Editor : public SmartGroupBox {
	Q_OBJECT
public:
	Editor(QWidget* p, const QString& title);
	virtual ~Editor();
};

#endif /*EDITOR_H_*/
