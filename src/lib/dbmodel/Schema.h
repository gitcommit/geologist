#ifndef SCHEMA_H_
#define SCHEMA_H_

#include <InDbModelElement.h>

#include <QtCore/QMap>

class Sequence;
class Table;

class Schema : public InDbModelElement {
	Q_OBJECT
public:
	Schema(DbModel* m = 0, const QString& name = QString::null);
	virtual ~Schema();
	virtual QStringList create() const;
	
	Sequence* registerSequence(Sequence* s);
	Sequence* sequence(const QString& name);
	QMap<QString, Sequence*> sequences() const { return _sequences; }
	
	Table* registerTable(Table* t);
	Table* table(const QString& name);
	QMap<QString, Table*> tables() const { return _tables; }
private:
	QMap<QString, Sequence*> _sequences;
	QMap<QString, Table*> _tables;
};

#endif /*SCHEMA_H_*/
