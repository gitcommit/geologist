#ifndef DATATYPE_H_
#define DATATYPE_H_

#include <InDbModelElement.h>

class DataType : public InDbModelElement {
	Q_OBJECT
public:
	DataType(DbModel* m = 0, const QString& name = QString::null, const QString& sqlName = QString::null);
	virtual ~DataType();
	virtual QStringList create() const;
	QString sqlName() const { return _sqlName; }
private:
	QString _sqlName;
};

#endif /*DATATYPE_H_*/
