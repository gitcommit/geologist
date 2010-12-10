#ifndef DBMODEL_H_
#define DBMODEL_H_

#include <QtCore/QObject>
#include <QtCore/QExplicitlySharedDataPointer>
#include <QtCore/QString>

#include <private/DbModelData.h>

class DbModel: public QObject {
	Q_OBJECT
public:
	DbModel(QObject* p = 0, const QString& name = QString::null);
	DbModel(const DbModel&other);
	virtual ~DbModel();
	
	void setName(const QString& n);
	QString name() const;
	QStringList create() const;
private:
	QExplicitlySharedDataPointer<DbModelData> d;
};

#endif