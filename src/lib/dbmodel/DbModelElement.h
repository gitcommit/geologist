#ifndef DBMODELELEMENT_H_
#define DBMODELELEMENT_H_

#include <QtCore/QObject>
#include <QtCore/QStringList>

class DbModelElement: public QObject
{
	Q_OBJECT
	Q_PROPERTY(QString name READ name WRITE setName)
public:
	DbModelElement(QObject* p = 0, const QString& name = QString::null);
	virtual ~DbModelElement();
	void setName(const QString& n) { _name = n; }
	QString name() const { return _name; }
	virtual QStringList create() const { return QStringList(); }
private:
	DbModelElement(const DbModelElement& other) {}
	QString _name;
};

#endif /*DBMODELELEMENT_H_*/
