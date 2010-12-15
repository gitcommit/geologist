#include <Lib/ORM/Mapping.h>

#include <Lib/ORM/Private/MappingData.h>

#include "Lib/DBModel/Table.h"

Mapping::Mapping(QObject* p, Table* t)
: QObject(p), _d(0) {
    _d = new MappingData();
    _d->setTable(t);
}

Mapping::Mapping(const Mapping& other)
: _d(other._d) {
}

Mapping::~Mapping() {
}

void Mapping::setTable(Table* t) {
    _d->setTable(t);
}

Table* Mapping::table() const {
    return _d->table();
}

QString Mapping::selectAllCursorName() const {
    return _d->selectAllCursorName();
}

QString Mapping::selectAllQuery() const {
    Q_CHECK_PTR(table());
}

DeclareSelectCursorQuery Mapping::declareSelectAllCursor() const {
    return DeclareSelectCursorQuery(selectAllCursorName(), selectAllQuery());
}

FetchAllInCursorQuery Mapping::fetchAllInSelectAllCursor() const {
    return FetchAllInCursorQuery(selectAllCursorName());
}

CloseCursorQuery Mapping::closeFetchAllCursor() const {
    return CloseCursorQuery(selectAllCursorName());
}