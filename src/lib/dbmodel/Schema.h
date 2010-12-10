#ifndef SCHEMA_H_
#define SCHEMA_H_

#include <InDbModelComponent.h>

#include <private/SchemaData.h>

class DbModel;

class Schema : public InDbModelComponent {
	Q_OBJECT
public:
	Schema(DbModel* dbM = 0, const QString& name = QString::null);
	Schema(const Schema& other);
	virtual ~Schema();

	void setName(const QString& n);
	QString name() const;
	QString qualifiedName() const;
	QStringList create() const;
	
	DbModel* dbModel();
private:
	QExplicitlySharedDataPointer<SchemaData> _d;
};

typedef QList<Schema*> SchemaList;

#endif /*SCHEMA_H_*/
