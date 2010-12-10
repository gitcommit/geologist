#ifndef DBMODEL_H_
#define DBMODEL_H_

#include <QtCore/QMap>

#include <DbModelElement.h>

class Schema;
class DataType;

class DbModel : public DbModelElement {
	Q_OBJECT
public:
	DbModel(QObject* p = 0, const QString& name=QString::null);
	virtual ~DbModel();
	Schema* createSchema(const QString& name);
	Schema* registerSchema(Schema* schema);
	Schema* schema(const QString& name);
	QMap<QString, Schema*> schemas() const { return _schemas; }
	
	DataType* createDataType(const QString& name, const QString& sqlName);
	DataType* registerDataType(DataType* t);
	DataType* dataType(const QString& name);
	QMap<QString, DataType*> dataTypes() const { return _dataTypes; }
	
	QStringList create() const;
protected:
	QStringList createDataTypes() const;
	QStringList createSchemas() const;
	QStringList createSequences(Schema* s) const;
private:
	DbModel(const DbModel& other) {}
	QMap<QString, Schema*> _schemas;
	QMap<QString, DataType*> _dataTypes;
};

#endif /*DBMODEL_H_*/
