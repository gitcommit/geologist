#ifndef TABLECOLUMN_H_
#define TABLECOLUMN_H_

#include <Lib/DBModel/InTableModelComponent.h>

#include <Lib/DBModel/private/TableColumnData.h>

class DataType;

class TableColumn : public InTableModelComponent {
	Q_OBJECT
public:
	TableColumn(Table* Table = 0, const QString& name = QString::null, DataType* dataType = 0, const bool& nullable = false);
	TableColumn(const TableColumn& other);
	virtual ~TableColumn();

	void setName(const QString& n);
	void setDataType(DataType* t);
	void setNullable(const bool& b);
	QString name() const;
	virtual QString qualifiedName() const;
	DataType* dataType() const;
	bool nullable() const;
	QStringList create() const;
private:
	QExplicitlySharedDataPointer<TableColumnData> _d;
};

typedef QList<TableColumn*> TableColumnList;

#endif /*TABLECOLUMN_H_*/
