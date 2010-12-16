#ifndef MAPPING_H_
#define MAPPING_H_

#include <QtCore/QObject>

#include <Lib/ORM/DeclareSelectCursorQuery.h>
#include <Lib/ORM/FetchAllInCursorQuery.h>
#include <Lib/ORM/CloseCursorQuery.h>

class MappingData;
class Table;

class Mapping {
public:
    Mapping(Table* t = 0);
    virtual ~Mapping();
    virtual void setTable(Table* t);
    virtual Table* table() const;
    virtual DeclareSelectCursorQuery declareSelectAllCursor(const qulonglong& queryId) const;
    virtual FetchAllInCursorQuery fetchAllInSelectAllCursor(const qulonglong& queryId) const;
    virtual CloseCursorQuery closeFetchAllCursor(const qulonglong& queryId) const;
protected:
    virtual QString selectAllCursorName() const;
    virtual QString selectAllQuery() const;
    MappingData* _d;
};

#endif /*MAPPING_H_*/
