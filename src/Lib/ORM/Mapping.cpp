#include <Lib/ORM/Mapping.h>

#include <Lib/ORM/Private/MappingData.h>

#include <QtCore/QStringList>

#include <Lib/DBModel/Table.h>
#include <Lib/DBModel/TableColumn.h>

Mapping::Mapping(Table* t)
: _d(0) {
    _d = new MappingData();
    _d->setTable(t);
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
    TableColumnList cols = table()->columns();
    QStringList cn;
    for(TableColumnList::const_iterator i = cols.begin(); i != cols.end(); i++) {
        cn << (*i)->name();
    }
    return QString("SELECT %1 FROM %2").arg(cn.join(", ")).arg(table()->qualifiedName());
}

DeclareSelectCursorQuery Mapping::declareSelectAllCursor(const qulonglong& queryId) const {
    return DeclareSelectCursorQuery(selectAllCursorName(), selectAllQuery(), queryId);
}

FetchAllInCursorQuery Mapping::fetchAllInSelectAllCursor(const qulonglong& queryId) const {
    return FetchAllInCursorQuery(selectAllCursorName(), queryId);
}

CloseCursorQuery Mapping::closeFetchAllCursor(const qulonglong& queryId) const {
    return CloseCursorQuery(selectAllCursorName(), queryId);
}