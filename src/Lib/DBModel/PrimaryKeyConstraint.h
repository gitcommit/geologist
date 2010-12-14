#ifndef PRIMARYKEYCONSTRAINT_H_
#define PRIMARYKEYCONSTRAINT_H_

#include <Lib/DBModel/TableConstraint.h>

#include <Lib/DBModel/Private/PrimaryKeyConstraintData.h>

class PrimaryKeyConstraint : public TableConstraint {
	Q_OBJECT
public:
	PrimaryKeyConstraint(Table* Table = 0, const QString& name = QString::null);
	PrimaryKeyConstraint(const PrimaryKeyConstraint& other);
	virtual ~PrimaryKeyConstraint();

	void setName(const QString& n);
	QString name() const;
	virtual QString qualifiedName() const;
	QStringList create() const;
	QStringList columnNames() const;
	void appendColumn(TableColumn* col);
private:
	QExplicitlySharedDataPointer<PrimaryKeyConstraintData> _d;
};

typedef QList<PrimaryKeyConstraint*> PrimaryKeyConstraintList;

#endif /*PRIMARYKEYCONSTRAINT_H_*/
