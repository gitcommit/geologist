/* 
 * File:   MappingXMLParser.h
 * Author: jolo
 *
 * Created on 16. Dezember 2010, 14:45
 */

#ifndef MAPPINGXMLPARSER_H
#define	MAPPINGXMLPARSER_H

#include <Lib/Tools/XMLFileParser.h>

class DataManager;

class MappingXMLParser: public XMLFileParser {
    Q_OBJECT
public:
    MappingXMLParser(QObject* p = 0);
    virtual ~MappingXMLParser();
protected:
    virtual void parse();
private:
    DataManager* createManager(QObject* p, const QString& moduleName,
        const QString& className, const QString& schemaName, const QString& tableName,
        const QString& managerClassName);
};

#endif	/* MAPPINGXMLPARSER_H */

