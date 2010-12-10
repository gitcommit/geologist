#ifndef DBMODEL_H_
#define DBMODEL_H_

#include <QtCore/QExplicitlySharedDataPointer>
#include <QtCore/QString>

#include <private/DbModelData.h>

class DbModel {
public:
	DbModel(const QString& name = QString::null);
	DbModel(const DbModel&other);
	virtual ~DbModel();
	void setName(const QString& n);
	QString name() const;
	QStringList create() const;
private:
	QExplicitlySharedDataPointer<DbModelData> d;
};

#endif