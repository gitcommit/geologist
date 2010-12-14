#ifndef SEQUENCE_H_
#define SEQUENCE_H_

#include <Lib/DBModel/InSchemaModelComponent.h>

#include <Lib/DBModel/private/SequenceData.h>

class Schema;

class Sequence : public InSchemaModelComponent {
	Q_OBJECT
public:
	Sequence(Schema* schema = 0, const QString& name = QString::null);
	Sequence(const Sequence& other);
	virtual ~Sequence();

	void setName(const QString& n);
	QString name() const;
	virtual QString qualifiedName() const;
	QStringList create() const;
private:
	QExplicitlySharedDataPointer<SequenceData> _d;
};

typedef QList<Sequence*> SequenceList;

#endif /*SEQUENCE_H_*/
