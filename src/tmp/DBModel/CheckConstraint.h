#ifndef CHECKCONSTRAINT_H_
#define CHECKCONSTRAINT_H_

#include <TableConstraint.h>

#include <private/CheckConstraintData.h>

class CheckConstraint : public TableConstraint {
	Q_OBJECT
public:
	CheckConstraint(Table* Table = 0, const QString& name = QString::null, const QString& definition = QString::null);
	CheckConstraint(const CheckConstraint& other);
	virtual ~CheckConstraint();

	void setName(const QString& n);
	void setDefinition(const QString& v);
	QString name() const;
	QString definition() const;
	virtual QString qualifiedName() const;
	QStringList create() const;
	QStringList columnNames() const;
	void appendColumn(TableColumn* col);
private:
	QExplicitlySharedDataPointer<CheckConstraintData> _d;
};

typedef QList<CheckConstraint*> CheckConstraintList;


#endif /*CHECKCONSTRAINT_H_*/
