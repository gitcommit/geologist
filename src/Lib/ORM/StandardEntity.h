#ifndef STANDARDENTITY_H_
#define STANDARDENTITY_H_

#include <Lib/ORM/IdentifiedEntity.h>

class StandardEntity : public IdentifiedEntity
{
	Q_OBJECT
	Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
	Q_PROPERTY(QString code READ code WRITE setCode NOTIFY codeChanged)
	Q_PROPERTY(QString description READ description WRITE setDescription NOTIFY descriptionChanged)
public:
	StandardEntity(QObject* p = 0,
			const qulonglong& id = 0,
			const QString& name = QString::null,
			const QString& code = QString::null,
			const QString& description = QString::null);
	StandardEntity(const StandardEntity& other);
	virtual ~StandardEntity();
	virtual void setName(const QString& n) = 0;
	virtual void setCode(const QString& c) = 0;
	virtual void setDescription(const QString& d) = 0;
	virtual QString name() const = 0;
	virtual QString code() const = 0;
	virtual QString description() const = 0;
signals:
	void nameChanged(const QString& newName);
	void codeChanged(const QString& newCode);
	void descriptionChanged(const QString& newDescription);
};

#endif /*STANDARDENTITY_H_*/
