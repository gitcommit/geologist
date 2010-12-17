/* 
 * File:   MappingXMLParser.cpp
 * Author: jolo
 * 
 * Created on 16. Dezember 2010, 14:45
 */

#include <Lib/ORM/MappingXMLParser.h>

#include <QtCore/QDebug>

#include <Lib/ORM/DataManager.h>

#include <Lib/DBModel/DBModel.h>
#include <Lib/DBModel/Schema.h>
#include <Lib/DBModel/Table.h>
#include <Lib/DBModel/TableColumn.h>

#include <Lib/Tools/tools.h>

#include <Lib/Model/Core/SIPrefixManager.h>

MappingXMLParser::MappingXMLParser(QObject* p)
: XMLFileParser(p) {
}

MappingXMLParser::~MappingXMLParser() {
}

void MappingXMLParser::parse() {
    QDomNodeList modules = documentElement().elementsByTagName("module");
    for (int mi = 0; mi != modules.size(); mi++) {
        QDomElement mE = modules.item(mi).toElement();
        Q_ASSERT(mE.hasAttribute("name"));
        QString moduleName = nameAttribute(modules.item(mi));
        QDomNodeList classes = mE.elementsByTagName("class");
        for (int ci = 0; ci != classes.size(); ci++) {
            QDomElement cE = classes.item(ci).toElement();
            Q_ASSERT(cE.hasAttribute("name"));
            Q_ASSERT(cE.hasAttribute("table_name"));
            Q_ASSERT(cE.hasAttribute("manager_class_name"));

            QString qualifiedTableName = cE.attribute("table_name");
            QString schemaName = qualifiedTableName.split(".")[0];
            QString tableName = qualifiedTableName.split(".")[1];
            QString className = nameAttribute(classes.item(ci));
            QString managerClassName = cE.attribute("manager_class_name");

            DataManager* manager = createManager(getApp(), moduleName,
                    className,
                    schemaName,
                    tableName,
                    managerClassName);
            QDomNodeList pl = cE.elementsByTagName("property");
            Schema* schema = getApp()->databaseModel()->schema(schemaName);
            Q_CHECK_PTR(schema);
            Table* table = schema->table(tableName);
            Q_CHECK_PTR(table);
            for (int i = 0; i != pl.size(); i++) {
                QDomElement pe = pl.item(i).toElement();
                Q_ASSERT(pe.hasAttribute("property_name"));
                Q_ASSERT(pe.hasAttribute("column_name"));
                TableColumn* col = table->column(pe.attribute("column_name"));
                Q_CHECK_PTR(col);
                qDebug() << QString("'%1' --> '%2'").arg(pe.attribute("property_name")).arg(col->pathName());
                (void) new Property(manager->mapping(), pe.attribute("property_name"), col);
            }
        }
    }
}

DataManager* MappingXMLParser::createManager(QObject* p, const QString& moduleName,
        const QString& className, const QString& schemaName, const QString& tableName,
        const QString& managerClassName) {
    if ("SIPrefixManager" == managerClassName) {
        return new SIPrefixManager(p, moduleName, className, schemaName, tableName);
    }
    return 0;
}