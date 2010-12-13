#ifndef BASE_H_
#define BASE_H_

#include <QtCore/QSharedData>
#include <QtCore/QString>

class Base: public QSharedData {
public:
	Base(const QString& name = QString::null);
	Base(const Base& other);
	virtual ~Base();
	void setName(const QString& n) { _name = n; }
	QString name() const { return _name; }
private:
	QString _name;
};


#endif /*BASE_H_*/
