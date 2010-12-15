#ifndef MAPPINGDATA_H_
#define MAPPINGDATA_H_

#include <QtCore/QSharedData>
#include <QtCore/QExplicitlySharedDataPointer>
#include <QtCore/QString>

class Table;

class MappingData : public QSharedData {
public:
    MappingData(Table* t = 0);
    MappingData(const MappingData& other);
    virtual ~MappingData();

    virtual void setTable(Table* t);
    Table* table() const {
        return _table;
    }
    bool hasTable() const {
        return (0 != _table);
    }
    void setSelectAllCursorName(const QString & s);

    virtual QString selectAllCursorName() const {
        return _selectAllCursorName;
    }

private:
    Table* _table;
    QString _selectAllCursorName;
};

#endif /*MAPPINGDATA_H_*/
