#ifndef DBMODELDATA_H_
#define DBMODELDATA_H_

#include <QtCore/QSharedData>
#include <QtCore/QString>

class DbModelData: public QSharedData {
public:
	DbModelData(const QString& name = QString::null);
	DbModelData(const DbModelData& other);
	virtual ~DbModelData();
	void setName(const QString& n) { _name = n; }
	QString name() const { return _name; }
private:
	QString _name;
};

#endif /*DBMODELDATA_H_*/
