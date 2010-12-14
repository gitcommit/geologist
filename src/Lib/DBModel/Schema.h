#ifndef SCHEMA_H_
#define SCHEMA_H_

#include <Lib/DBModel/InDBModelComponent.h>

#include <Lib/DBModel/Private/SchemaData.h>

class DBModel;
class Table;

class Schema : public InDBModelComponent {
	Q_OBJECT
public:
	Schema(DBModel* dbM = 0, const QString& name = QString::null);
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
