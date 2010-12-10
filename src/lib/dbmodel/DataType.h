#ifndef DATATYPE_H_
#define DATATYPE_H_

#include <InDbModelComponent.h>

#include <private/DataTypeData.h>

class DbModel;

class DataType : public InDbModelComponent {
	Q_OBJECT
public:
	DataType(DbModel* dbM = 0, const QString& name = QString::null, const QString& sqlName = QString::null);
	DataType(const DataType& other);
	virtual ~DataType();

	void setName(const QString& n);
	void setSqlName(const QString& n);
	QString name() const;
	QString sqlName() const;
	QString qualifiedName() const;
	QStringList create() const;
private:
	QExplicitlySharedDataPointer<DataTypeData> _d;
};

typedef QList<DataType*> DataTypeList;

#endif /*DATATYPE_H_*/
