#ifndef STANDARDENTITYDATA_H_
#define STANDARDENTITYDATA_H_

#include <Lib/ORM/Private/IdentifiedEntityData.h>

#include <QtCore/QString>

class StandardEntityData: public IdentifiedEntityData
{
public:
	StandardEntityData(const qulonglong& id = 0,
			const QString& name = QString::null,
			const QString& code = QString::null,
			const QString& description = QString::null);
	StandardEntityData(const StandardEntityData& other);
	virtual ~StandardEntityData();
	
	virtual void setName(const QString& n) { _name = n; }
	virtual void setCode(const QString& c) { _code = c; }
	virtual void setDescription(const QString& d) { _description = d; }
	virtual bool hasName() const { return (!name().isEmpty()); }
	virtual bool hasCode() const { return (!code().isEmpty());}
	virtual bool hasDescription() const { return (!description().isEmpty()); }
	virtual QString name() const { return _name; }
	virtual QString code() const { return _code; }
	virtual QString description() const { return _description; }
	
private:
	QString _name;
	QString _code;
	QString _description;
};

#endif /*STANDARDENTITYDATA_H_*/
