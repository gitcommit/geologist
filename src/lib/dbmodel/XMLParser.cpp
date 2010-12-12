#include <XMLParser.h>

#include <QtCore/QFile>
#include <QtCore/QDebug>
#include <QtGui/QApplication>

XMLParser::XMLParser(QObject* p) :
	QObject(p) {
}

XMLParser::~XMLParser() {
}

void XMLParser::loadFromFile(const QString& fileName) {
	QFile f(fileName);
	if (!f.open(QIODevice::ReadOnly)) {
		qFatal(tr("Could not open file %1 for reading.").arg(fileName).toLocal8Bit());
	}
	if (!_doc.setContent(&f)) {
		f.close();
		qFatal(tr("Could not read XML from %1.").arg(fileName).toLocal8Bit());
	}
	f.close();
	parse();
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
		emit createDataType(e.attribute("name"), e.attribute("sql_name"), stringToBool(e.attribute("requires_quoting", "false")));
	}
}

void XMLParser::createSequences(const QString& schemaName,
		const QDomNodeList& sequences) const {
	for (int i = 0; i != sequences.size(); i++) {
		emit createSequence(schemaName, nameAttribute(sequences.item(i)));
	}
}

void XMLParser::createTables(const QString& schemaName,
		const QDomNodeList& tables) const {
	for (int i = 0; i != tables.size(); i++) {
		QString tableName = nameAttribute(tables.item(i));
		emit createTable(schemaName, tableName);
		createTableColumns(schemaName, tableName, tables.item(i).toElement().elementsByTagName("column"));
	}
}

void XMLParser::createTableColumns(const QString& schemaName,
		const QString& tableName, const QDomNodeList& cols) const {
	for (int i = 0; i != cols.size(); i++) {
		emit createTableColumn(schemaName, tableName,
				nameAttribute(cols.item(i)),
				nameAttribute(dataTypeElementByName(cols.item(i).toElement().attribute("type"))));
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

QString XMLParser::nameAttribute(const QDomNode& n) const {
	QDomElement e = n.toElement();
	Q_ASSERT(!e.isNull());
	Q_ASSERT(e.hasAttribute("name"));
	return e.attribute("name");
}

QDomElement XMLParser::documentElement() const {
	return _doc.documentElement();
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
	QApplication::processEvents();
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
}

bool XMLParser::stringToBool(const QString& s) const {
	if ("true" == s) {
		return true;
	}
	return false;
}