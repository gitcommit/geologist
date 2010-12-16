#ifndef XMLFILEPARSER_H_
#define XMLFILEPARSER_H_

#include <QtCore/QObject>

#include <QtCore/QString>
#include <QtCore/QStringList>
#include <QtXml/QDomDocument>
#include <QtXml/QDomElement>

class XMLFileParser : public QObject {
    Q_OBJECT
public:
    XMLFileParser(QObject* p = 0);
    virtual ~XMLFileParser();
    virtual void loadFromFile(const QString& fileName);

protected:
    QDomDocument document() const { return _doc; }
    virtual QDomElement documentElement() const;
    virtual QString nameAttribute(const QDomNode& n) const;
    virtual bool stringToBool(const QString& str) const;
    
    virtual void parse() = 0;
private:
    QDomDocument _doc;
};

#endif /*XMLFileParser_H_*/
