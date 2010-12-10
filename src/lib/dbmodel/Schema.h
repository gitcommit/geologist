#ifndef SCHEMA_H_
#define SCHEMA_H_

#include <InDbModelElement.h>

#include <QtCore/QMap>

class Sequence;

class Schema : public InDbModelElement {
	Q_OBJECT
public:
	Schema(DbModel* m = 0, const QString& name = QString::null);
	virtual ~Schema();
	virtual QStringList create() const;
	
	Sequence* createSequence(const QString& name);
	Sequence* registerSequence(Sequence* s);
	Sequence* sequence(const QString& name);
	QMap<QString, Sequence*> sequences() const { return _sequences; }
private:
	QMap<QString, Sequence*> _sequences;
};

#endif /*SCHEMA_H_*/