#ifndef SCHEMADATA_H_
#define SCHEMADATA_H_

#include <QtCore/QSharedData>
#include <QtCore/QString>

class SchemaData : public QSharedData {
public:
	SchemaData(const QString& name = QString::null);
	SchemaData(const SchemaData& other);
	virtual ~SchemaData();

	void setName(const QString& n) {
		_name = n;
	}
	QString name() const {
		return _name;
	}
private:
	QString _name;
};

#endif /*SCHEMADATA_H_*/
