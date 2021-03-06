#ifndef DBXMLPARSER_H_
#define DBXMLPARSER_H_

#include <Lib/Tools/XMLFileParser.h>

#include <QtCore/QString>
#include <QtXml/QDomDocument>
#include <QtXml/QDomElement>

class DBXMLParser : public XMLFileParser {
    Q_OBJECT
public:
    DBXMLParser(QObject* p = 0);
    virtual ~DBXMLParser();
    
signals:
    void createDataType(const QString& name, const QString& sqlName, const bool& requiresQuoting) const;
    void createSchema(const QString& name) const;
    void createSequence(const QString& schema, const QString& name) const;
    void createTable(const QString& schema, const QString& name) const;
    void createTableColumn(const QString& schema, const QString& table, const QString& columnName, const QString& dataType, const bool& nullable) const;
    void createPrimaryKeyConstraint(const QString& schemaName, const QString& tableName, const QString& name, const QStringList& columnNames) const;
    void createUniqueConstraint(const QString& schemaName, const QString& tableName, const QString& name, const QStringList& columnNames) const;
    void createCheckConstraint(const QString& schemaName, const QString& tableName, const QString& name, const QStringList& columnNames, const QString& check) const;
    void createForeignKeyConstraint(const QString& name,
            const QString& schemaName, const QString& tableName, const QStringList& columnNames,
            const QString& referencedSchemaName, const QString& referencedTableName, const QStringList& referencedColumnNames) const;

protected:
    virtual void parse();
    virtual void createDataTypes(const QDomNodeList& types) const;
    virtual void createSchemata(const QDomNodeList& schemata) const;
    virtual void createSequences(const QString& schemaName, const QDomNodeList& sequences) const;
    virtual void createTables(const QString& schemaName, const QDomNodeList& tables) const;
    virtual void createTableColumns(const QString& schemaName, const QString& tableName, const QDomNodeList& cols) const;
    virtual void createPrimaryKeyConstraints(const QString& schemaName, const QString& tableName, const QDomNodeList& pk) const;
    virtual void createUniqueConstraints(const QString& schemaName, const QString& tableName, const QDomNodeList& un) const;
    virtual void createCheckConstraints(const QString& schemaName, const QString& tableName, const QDomNodeList& un) const;
    virtual void createForeignKeyConstraints(const QString& schemaName, const QString& tableName, const QDomNodeList& un) const;

    QDomElement dbElement() const;
    QDomElement dataTypeElementByName(const QString& name) const;
    QStringList constraintColumnNames(const QDomNode& constraintNode) const;

private:
    QDomDocument _doc;
};

#endif /*DBXMLPARSER_H_*/
