#include <Lib/Tools/XMLFileParser.h>

#include <QtCore/QFile>
#include <QtCore/QStringList>

XMLFileParser::XMLFileParser(QObject* p)
: QObject(p) {
}

XMLFileParser::~XMLFileParser() {
}

void XMLFileParser::loadFromFile(const QString& fileName) {
    QFile f(fileName);
    QString msg;
    int line;
    int col;
    if (!f.open(QIODevice::ReadOnly)) {
        qFatal(tr("Could not open file %1 for reading.").arg(fileName).toLocal8Bit());
    }
    if (!_doc.setContent(&f, &msg, &line, &col)) {
        f.close();
        qFatal(tr("Could not read XML from %1: %2 at %3:%4").arg(fileName).arg(msg).arg(line).arg(col).toLocal8Bit());
    }
    f.close();
    parse();
}

QString XMLFileParser::nameAttribute(const QDomNode& n) const {
    QDomElement e = n.toElement();
    Q_ASSERT(!e.isNull());
    Q_ASSERT(e.hasAttribute("name"));
    return e.attribute("name");
}

QDomElement XMLFileParser::documentElement() const {
    return _doc.documentElement();
}

bool XMLFileParser::stringToBool(const QString& s) const {
    if ("true" == s) {
        return true;
    }
    return false;
}