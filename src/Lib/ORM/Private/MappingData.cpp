#include <Lib/ORM/Private/MappingData.h>

#include <Lib/DBModel/Table.h>

MappingData::MappingData(Table* t)
: QSharedData(), _table(t) {
    setTable(t);
}

MappingData::MappingData(const MappingData& other)
: QSharedData(other), _table(other._table) {
}

MappingData::~MappingData() {
}

void MappingData::setSelectAllCursorName(const QString& s) {
    _selectAllCursorName = s;
}

void MappingData::setTable(Table* t) {
    _table = t;
    if (hasTable()) {
        setSelectAllCursorName(QString("ALL_IN_%1").arg(table()->joinedName()));
    }
}