#ifndef STANDARDENTITY_H_
#define STANDARDENTITY_H_

#include <IdentifiedEntity.h>

class StandardEntity : public IdentifiedEntity
{
	Q_OBJECT
	Q_PROPERTY(QString name READ name WRITE setName)
	Q_PROPERTY(QString code READ code WRITE setCode)
	Q_PROPERTY(QString description READ description WRITE setDescription)
public:
	StandardEntity(QObject* p = 0,
			const qulonglong& id = 0,
			const QString& name = QString::null,
			const QString& code = QString::null,
			const QString& description = QString::null);
	virtual ~StandardEntity();
	virtual void setName(const QString& n) { _name = n; }
	virtual void setCode(const QString& c) { _code = c; }
	virtual void setDescription(const QString& d) { _description = d; }
	QString name() const { return _name; }
	QString code() const { return _code; }
	QString description() const { return _description; }
private:
	StandardEntity(const StandardEntity& other);
	QString _name;
	QString _code;
	QString _description;
};

#endif /*STANDARDENTITY_H_*/
