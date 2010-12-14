#include <Lib/GUI/Widgets/PasswordEdit.h>

PasswordEdit::PasswordEdit(QWidget* p, const QString& lbl, const QString& value) :
	LineEdit(p, lbl, value) {
	setEchoMode(QLineEdit::Password);
}

PasswordEdit::~PasswordEdit() {
}
