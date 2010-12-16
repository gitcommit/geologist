#ifndef DBMODEL_H_
#define DBMODEL_H_

#include <Lib/DBModel/ModelComponent.h>

#include <QtCore/QExplicitlySharedDataPointer>
#include <QtCore/QString>

#include <Lib/DBModel/Private/DBModelData.h>

class Schema;
class DataType;

class DBXMLParser;

class DBModel : public ModelComponent {
    Q_OBJECT
public:
    DBModel(QObject* p = 0, const QString& name = QString::null);
    DBModel(const DBModel& other);
    virtual ~DBModel();

    QString name() const;
    QString qualifiedName() const;
    virtual QStringList create() const;
    Schema* schema(const QString& name) const;
    DataType* dataType(const QString& name) const;
public slots:
    void setName(const QString& n);
    void loadFromFile(const QString& fn);
    void createDataType(const QString& name, const QString& sqlName, const bool& requiresQuoting);
    void createSchema(const QString& name);
    void createSequence(const QString& schemaName, const QString& sequenceName);
    void createTable(const QString& schemaName, const QString& tableName);
    void createTableColumn(const QString& schemaName, const QString& tableName, const QString& colName, const QString& typeName, const bool& nullable);
    void createPrimaryKeyConstraint(const QString& schemaName, const QString& tableName, const QString& name, const QStringList& columnNames);
    void createUniqueConstraint(const QString& schemaName, const QString& tableName, const QString& name, const QStringList& columnNames);
    void createCheckConstraint(const QString& schemaName, const QString& tableName, const QString& name, const QStringList& columnNames, const QString& definition);
    void createForeignKeyConstraint(const QString& name,
            const QString& schemaName, const QString& tableName, const QStringList& columnNames,
            const QString& referencedSchemaName, const QString& referencedTableName, const QStringList& referencedColumnNames);
protected:
    virtual QStringList createDataTypes() const;
    virtual QStringList createSequences() const;
    virtual QStringList createSchemas() const;
    virtual QStringList createTables() const;
    virtual QStringList createTableColumns() const;
    virtual QStringList createPrimaryKeyConstraints() const;
    virtual QStringList createUniqueConstraints() const;
    virtual QStringList createCheckConstraints() const;
    virtual QStringList createForeignKeyConstraints() const;
private:
    QExplicitlySharedDataPointer<DBModelData> _d;
    DBXMLParser* _parser;
};

#endif
