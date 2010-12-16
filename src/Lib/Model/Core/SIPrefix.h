#ifndef SI_PREFIX_H
#define SI_PREFIX_H

#include <Lib/ORM/StandardEntity.h>

#include <QtCore/QString>
#include <QtCore/QObject>
#include <QtCore/QExplicitlySharedDataPointer>

class SIPrefixData;

class SIPrefix : public StandardEntity {
    Q_OBJECT
    Q_CLASSINFO("module", "Core");
    Q_PROPERTY(QString symbol READ symbol WRITE setSymbol NOTIFY symbolChanged)
    Q_PROPERTY(qreal factor READ factor WRITE setFactor NOTIFY factorChanged)
public:
    SIPrefix(QObject* p = 0,
            const qulonglong& id = 0, const QString& name = QString::null,
            const QString& code = QString::null,
            const QString& symbol = QString::null, const qreal& factor = 0.0,
            const QString& description = QString::null);
    SIPrefix(const SIPrefix& other);
    virtual ~SIPrefix();

    virtual void setId(const qulonglong& id);
    virtual void setName(const QString& name);
    virtual void setCode(const QString& code);
    virtual void setSymbol(const QString& s);
    virtual void setFactor(const qreal& r);
    virtual void setDescription(const QString& d);

    virtual qulonglong id() const;
    virtual QString name() const;
    virtual QString code() const;
    virtual QString symbol() const;
    virtual qreal factor() const;
    virtual QString description() const;

    virtual bool hasId() const;
    virtual QString toString() const;

signals:
    void symbolChanged(const QString& newSymbol);
    void factorChanged(const qreal& newFacto);
protected:
    QExplicitlySharedDataPointer<SIPrefixData> _d;
};

#endif // SI_PREFIX_H
