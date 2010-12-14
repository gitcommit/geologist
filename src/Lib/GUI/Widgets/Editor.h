#ifndef EDITOR_H_
#define EDITOR_H_

#include <Lib/GUI/Widgets/SmartGroupBox.h>

class Editor : public SmartGroupBox {
	Q_OBJECT
public:
	Editor(QWidget* p, const QString& title);
	virtual ~Editor();
};

#endif /*EDITOR_H_*/
