#include <Lib/DBModel/XMLParser.h>

XMLParser::XMLParser(QObject* p)
: XMLFileParser(p) {
}

XMLParser::~XMLParser() {
}

void XMLParser::createSchemata(const QDomNodeList& schemata) const {
    for (int schemaI = 0; schemaI != schemata.size(); schemaI++) {
        QDomElement schemaE = schemata.item(schemaI).toElement();
        Q_ASSERT(schemaE.hasAttribute("name"));
        QString schemaName = schemaE.attribute("name");
        emit createSchema(schemaName);
    }
}

void XMLParser::createDataTypes(const QDomNodeList& types) const {
    for (int i = 0; i != types.size(); i++) {
        QDomElement e = types.item(i).toElement();
        Q_ASSERT(e.hasAttribute("name"));
        Q_ASSERT(e.hasAttribute("sql_name"));
        emit createDataType(e.attribute("name"), e.attribute("sql_name"),
                stringToBool(e.attribute("requires_quoting", "false")));
    }
}

void XMLParser::createSequences(const QString& schemaName,
        const QDomNodeList& sequences) const {
    for (int i = 0; i != sequences.size(); i++) {
        emit createSequence(schemaName, nameAttribute(sequences.item(i)));
    }
}

QStringList XMLParser::constraintColumnNames(const QDomNode& constraintNode) const {
    QStringList ret;
    QDomNodeList lst = constraintNode.toElement().elementsByTagName("constraint_column");
    for (int i = 0; i != lst.size(); i++) {
        ret.append(nameAttribute(lst.item(i)));
    }
    return ret;
}

void XMLParser::createPrimaryKeyConstraints(const QString& schemaName,
        const QString& tableName, const QDomNodeList& pk) const {
    Q_ASSERT(pk.size() <= 1);
    for (int i = 0; i != pk.size(); i++) {
        emit createPrimaryKeyConstraint(schemaName, tableName,
                nameAttribute(pk.item(i)), constraintColumnNames(pk.item(i)));
    }
}

void XMLParser::createUniqueConstraints(const QString& schemaName,
        const QString& tableName, const QDomNodeList& nodes) const {
    for (int i = 0; i != nodes.size(); i++) {
        emit createUniqueConstraint(schemaName, tableName,
                nameAttribute(nodes.item(i)),
                constraintColumnNames(nodes.item(i)));
    }
}

void XMLParser::createForeignKeyConstraints(const QString& schemaName,
        const QString& tableName, const QDomNodeList& nodes) const {
    for (int i = 0; i != nodes.size(); i++) {
        QDomElement e = nodes.item(i).toElement();
        QStringList lcn;
        QStringList rcn;
        QString referencedSchemaName = e.attribute("referenced_table_name").split(".")[0];
        QString referencedTableName = e.attribute("referenced_table_name").split(".")[1];

        QDomNodeList pairs = e.elementsByTagName("column_pair");
        Q_ASSERT(0 != pairs.size());
        for (int ii = 0; ii != pairs.size(); ii++) {
            QDomElement ee = pairs.item(ii).toElement();
            Q_ASSERT(ee.hasAttribute("local_column_name"));
            Q_ASSERT(ee.hasAttribute("referenced_column_name"));
            lcn.append(ee.attribute("local_column_name"));
            rcn.append(ee.attribute("referenced_column_name"));
        }
        emit createForeignKeyConstraint(nameAttribute(nodes.item(i)),
                schemaName, tableName, lcn, referencedSchemaName,
                referencedTableName, rcn);
    }
}

void XMLParser::createCheckConstraints(const QString& schemaName,
        const QString& tableName, const QDomNodeList& nodes) const {
    for (int i = 0; i != nodes.size(); i++) {
        emit createCheckConstraint(schemaName, tableName,
                nameAttribute(nodes.item(i)),
                constraintColumnNames(nodes.item(i)), nodes.item(i).toElement().attribute("definition"));
    }
}

void XMLParser::createTables(const QString& schemaName,
        const QDomNodeList& tables) const {
    for (int i = 0; i != tables.size(); i++) {
        QString tableName = nameAttribute(tables.item(i));
        emit createTable(schemaName, tableName);
        createTableColumns(schemaName, tableName, tables.item(i).toElement().elementsByTagName("column"));
        createPrimaryKeyConstraints(schemaName, tableName, tables.item(i).toElement().elementsByTagName("primary_key_constraint"));
        createUniqueConstraints(schemaName, tableName, tables.item(i).toElement().elementsByTagName("unique_constraint"));
        createCheckConstraints(schemaName, tableName, tables.item(i).toElement().elementsByTagName("check_constraint"));
    }
}

void XMLParser::createTableColumns(const QString& schemaName,
        const QString& tableName, const QDomNodeList& cols) const {
    for (int i = 0; i != cols.size(); i++) {
        emit createTableColumn(schemaName, tableName,
                nameAttribute(cols.item(i)),
                nameAttribute(dataTypeElementByName(cols.item(i).toElement().attribute("type"))),
                stringToBool(cols.item(i).toElement().attribute("nullable")));
    }
}

QDomElement XMLParser::dataTypeElementByName(const QString& dataTypeName) const {
    QDomNodeList l = dbElement().elementsByTagName("data_type");
    for (int i = 0; i != l.size(); i++) {
        if (dataTypeName == nameAttribute(l.item(i))) {
            return l.item(i).toElement();
        }
    }
    return QDomElement();
}

QDomElement XMLParser::dbElement() const {
    return documentElement().elementsByTagName("database").item(0).toElement();
}

void XMLParser::parse() {
    QDomElement dbEl = dbElement();
    Q_ASSERT(!dbEl.isNull());
    QDomNodeList schemata = dbEl.elementsByTagName("schema");
    createDataTypes(dbEl.elementsByTagName("data_type"));
    createSchemata(schemata);
    for (int schemaI = 0; schemaI != schemata.size(); schemaI++) {
        QDomNode schemaN = schemata.item(schemaI);
        QString schemaName = nameAttribute(schemaN);
        createSequences(schemaName, schemaN.toElement().elementsByTagName("sequence"));
    }
    for (int schemaI = 0; schemaI != schemata.size(); schemaI++) {
        QDomNode schemaN = schemata.item(schemaI);
        QString schemaName = nameAttribute(schemaN);
        createTables(schemaName, schemaN.toElement().elementsByTagName("table"));
    }
    for (int schemaI = 0; schemaI != schemata.size(); schemaI++) {
        QDomNode schemaN = schemata.item(schemaI);
        QString schemaName = nameAttribute(schemaN);
        QDomNodeList tables = schemaN.toElement().elementsByTagName("table");
        for (int i = 0; i != tables.size(); i++) {
            createForeignKeyConstraints(schemaName, nameAttribute(tables.item(i)), tables.item(i).toElement().elementsByTagName("foreign_key_constraint"));
        }
    }
}
