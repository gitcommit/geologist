#ifndef TABLEDATA_H_
#define TABLEDATA_H_

#include <QtCore/QSharedData>
#include <QtCore/QString>

class TableData : public QSharedData {
public:
	TableData(const QString& name = QString::null);
	TableData(const TableData& other);
	virtual ~TableData();

	void setName(const QString& n) {
		_name = n;
	}
	QString name() const {
		return _name;
	}
private:
	QString _name;
};

#endif /*TABLEDATA_H_*/
