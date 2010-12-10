#ifndef TABLE_H_
#define TABLE_H_

#include <InSchemaModelComponent.h>

#include <private/TableData.h>

class Schema;

class Table : public InSchemaModelComponent {
	Q_OBJECT
public:
	Table(Schema* schema = 0, const QString& name = QString::null);
	Table(const Table& other);
	virtual ~Table();

	void setName(const QString& n);
	QString name() const;
	virtual QString qualifiedName() const;
	QStringList create() const;
private:
	QExplicitlySharedDataPointer<TableData> _d;
};

typedef QList<Table*> TableList;

#endif /*TABLE_H_*/
