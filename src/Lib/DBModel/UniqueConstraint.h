#ifndef UNIQUECONSTRAINT_H_
#define UNIQUECONSTRAINT_H_

#include <Lib/DBModel/TableConstraint.h>

#include <Lib/DBModel/private/UniqueConstraintData.h>

class UniqueConstraint : public TableConstraint {
	Q_OBJECT
public:
	UniqueConstraint(Table* Table = 0, const QString& name = QString::null);
	UniqueConstraint(const UniqueConstraint& other);
	virtual ~UniqueConstraint();

	void setName(const QString& n);
	QString name() const;
	virtual QString qualifiedName() const;
	QStringList create() const;
	QStringList columnNames() const;
	void appendColumn(TableColumn* col);
private:
	QExplicitlySharedDataPointer<UniqueConstraintData> _d;
};

typedef QList<UniqueConstraint*> UniqueConstraintList;

#endif /*UNIQUECONSTRAINT_H_*/
