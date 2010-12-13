#ifndef PASSWORDEDIT_H_
#define PASSWORDEDIT_H_

#include <LineEdit.h>

class PasswordEdit : public LineEdit {
	Q_OBJECT
public:
	PasswordEdit(QWidget* p, const QString& txt, const QString& value=QString::null);
	virtual ~PasswordEdit();
};

#endif /*PASSWORDEDIT_H_*/
