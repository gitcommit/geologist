#ifndef STANDARDENTITY_H_
#define STANDARDENTITY_H_

#include <IdentifiedEntity.h>

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
	virtual ~StandardEntity();
	virtual void setName(const QString& n) { _name = n; emit nameChanged(); }
	virtual void setCode(const QString& c) { _code = c; emit codeChanged(); }
	virtual void setDescription(const QString& d) { _description = d; emit descriptionChanged(); }
	QString name() const { return _name; }
	QString code() const { return _code; }
	QString description() const { return _description; }
	
signals:
	void nameChanged();
	void codeChanged();
	void descriptionChanged();
private:
	StandardEntity(const StandardEntity& other);
	QString _name;
	QString _code;
	QString _description;
};

#endif /*STANDARDENTITY_H_*/
