#ifndef SCHEMA_H_
#define SCHEMA_H_

#include <InDbModelComponent.h>

#include <private/SchemaData.h>

class DbModel;
class Table;

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
	Table* table(const QString& name) const;
private:
	QExplicitlySharedDataPointer<SchemaData> _d;
};

typedef QList<Schema*> SchemaList;

#endif /*SCHEMA_H_*/
