#ifndef DATATYPE_H_
#define DATATYPE_H_

#include <Lib/DBModel/InDBModelComponent.h>

#include <Lib/DBModel/Private/DataTypeData.h>

class DBModel;

class DataType : public InDBModelComponent {
	Q_OBJECT
public:
	DataType(DBModel* dbM = 0, const QString& name = QString::null, const QString& sqlName = QString::null,
			const bool& requiresQuoting = false);
	DataType(const DataType& other);
	virtual ~DataType();

	void setName(const QString& n);
	void setSqlName(const QString& n);
	void setRequiresQuoting(const bool& b);
	QString name() const;
	QString sqlName() const;
	QString qualifiedName() const;
	bool requiresQuoting() const;
	QStringList create() const;
private:
	QExplicitlySharedDataPointer<DataTypeData> _d;
};

typedef QList<DataType*> DataTypeList;

#endif /*DATATYPE_H_*/
