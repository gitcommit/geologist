#ifndef DBMODEL_H_
#define DBMODEL_H_

#include <ModelComponent.h>

#include <QtCore/QExplicitlySharedDataPointer>
#include <QtCore/QString>

#include <private/DbModelData.h>

class DbModel: public ModelComponent {
	Q_OBJECT
public:
	DbModel(QObject* p = 0, const QString& name = QString::null);
	DbModel(const DbModel& other);
	virtual ~DbModel();
	
	void setName(const QString& n);
	QString name() const;
	QString qualifiedName() const;
	virtual QStringList create() const;
protected:
	virtual QStringList createSchemas() const;
	virtual QStringList createTables() const;
private:
	QExplicitlySharedDataPointer<DbModelData> _d;
};

#endif