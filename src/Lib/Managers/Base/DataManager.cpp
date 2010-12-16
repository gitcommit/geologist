/* 
 * File:   DataManager.cpp
 * Author: jolo
 * 
 * Created on 16. Dezember 2010, 09:55
 */

#include <Lib/Managers/Base/DataManager.h>

#include <QtCore/QStringList>
#include <QtCore/QDebug>

#include <Lib/Tools/tools.h>

#include <Lib/DBModel/DBModel.h>
#include <Lib/DBModel/Schema.h>
#include <Lib/DBModel/Table.h>
#include <Lib/DBModel/TableColumn.h>

#include <Lib/ORM/Property.h>

DataManager::DataManager(QObject* p, const QString& fn, const QString& modN, const QString& clN)
: QObject(p), _mapping(0), _mappingFileName(fn), _moduleName(modN), _className(clN) {
    connect(this, SIGNAL(execRequest(const DeclareSelectCursorQuery&)), getApp()->databaseThread(), SLOT(onQueryRequest(const DeclareSelectCursorQuery&)));
    connect(this, SIGNAL(execRequest(const FetchAllInCursorQuery&)), getApp()->databaseThread(), SLOT(onQueryRequest(const FetchAllInCursorQuery&)));
    connect(this, SIGNAL(execRequest(const CloseCursorQuery&)), getApp()->databaseThread(), SLOT(onQueryRequest(const CloseCursorQuery&)));

    connect(getApp()->databaseThread(), SIGNAL(queryCompleted(const DeclareSelectCursorQuery&)), this, SLOT(onQueryCompleted(const DeclareSelectCursorQuery&)));
    connect(getApp()->databaseThread(), SIGNAL(queryCompleted(const FetchAllInCursorQuery&)), this, SLOT(onQueryCompleted(const FetchAllInCursorQuery&)));

    configure();
}

DataManager::~DataManager() {
}

qulonglong DataManager::nextQueryId() {
    _qid = getApp()->nextQueryId();
    return _qid;
}

qulonglong DataManager::queryId() const {
    return _qid;
}

bool DataManager::isMyQuery(const Query* q) const {
    Q_CHECK_PTR(q);
    return (q->id() == queryId());
}

void DataManager::loadAll() {
    emit execRequest(mapping()->declareSelectAllCursor(nextQueryId()));
}

void DataManager::onQueryCompleted(const DeclareSelectCursorQuery& q) {
    if (!isMyQuery(&q)) {
        return;
    }
    emit execRequest(mapping()->fetchAllInSelectAllCursor(nextQueryId()));
}

void DataManager::onQueryCompleted(const FetchAllInCursorQuery& q) {
    if (!isMyQuery(&q)) {
        return;
    }
    emit execRequest(mapping()->closeFetchAllCursor(nextQueryId()));
}

QDomDocument DataManager::domDocument() const {
    QDomDocument doc;
    QFile f(mappingFileName());
    QString msg;
    int line;
    int col;
    if (!f.open(QIODevice::ReadOnly)) {
        qFatal(tr("Could not open file %1 for reading.").arg(mappingFileName()).toLocal8Bit());
    }
    if (!doc.setContent(&f, &msg, &line, &col)) {
        f.close();
        qFatal(tr("Could not read XML from %1: %2 at %3:%4").arg(mappingFileName()).arg(msg).arg(line).arg(col).toLocal8Bit());
    }
    f.close();
    return doc;
}

QDomNode DataManager::moduleNode(const QString& moduleName) {
    QDomElement docEl = domDocument().documentElement();
    QDomNodeList l = docEl.elementsByTagName("module");
    for (int i = 0; i < l.size(); i++) {
        QDomElement e = l.item(i).toElement();
        Q_ASSERT(e.hasAttribute("name"));
        if (moduleName == e.attribute("name")) {
            return l.item(i);
        }
    }
    qFatal(tr("DataManager: no module %1 in configuration file %2").arg(moduleName).arg(mappingFileName()).toLocal8Bit());
    return QDomNode();
}

QDomNode DataManager::classNode(const QString& moduleName, const QString& className) {
    QDomNode moduleN = moduleNode(moduleName);
    Q_ASSERT(!moduleN.isNull());
    QDomNodeList l = moduleN.toElement().elementsByTagName("class");
    for (int i = 0; i < l.size(); i++) {
        QDomElement e = l.item(i).toElement();
        Q_ASSERT(e.hasAttribute("name"));
        if (className == e.attribute("name")) {
            return l.item(i);
        }
    }
    qFatal(tr("DataManager: no class %1 in module %2 in configuration file %3")
            .arg(className)
            .arg(moduleName)
            .arg(mappingFileName()).toLocal8Bit());
    return QDomNode();
}

void DataManager::configure() {
    QDomElement e = classNode(moduleName(), className()).toElement();
    Q_ASSERT(!e.isNull());
    Q_ASSERT(e.hasAttribute("table_name"));
    QString qualifiedTableName = e.attribute("table_name");
    Schema* schema = getApp()->databaseModel()->schema(qualifiedTableName.split(".")[0]);
    Q_CHECK_PTR(schema);
    Table* table = schema->table(qualifiedTableName.split(".")[1]);
    Q_CHECK_PTR(table);
    setMapping(new Mapping(table));
    
    QDomNodeList l = e.elementsByTagName("property");
    for (int i = 0; i != l.size(); i++) {
        QDomElement pe = l.item(i).toElement();
        Q_ASSERT(pe.hasAttribute("property_name"));
        Q_ASSERT(pe.hasAttribute("column_name"));
        TableColumn* col = table->column(pe.attribute("column_name"));
        Q_CHECK_PTR(col);
        qDebug() << QString("'%1' --> '%2'").arg(pe.attribute("property_name")).arg(col->pathName());
        (void) new Property(mapping(), pe.attribute("property_name"), col);
    }
}
