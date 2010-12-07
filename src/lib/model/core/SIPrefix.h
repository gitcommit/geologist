#ifndef SI_PREFIX_H
#define SI_PREFIX_H

#include <Entity.h>

#include <QtCore/QString>
#include <QtCore/QObject>

class SIPrefix : public Entity {
public:
	SIPrefix(const qulonglong& id = 0, const QString& name = QString::null,
			const QString& code = QString::null,
			const QString& symbol = QString::null, const qreal& factor = 0.0,
			const QString& description = QString::null);
	SIPrefix(const SIPrefix& other);
	virtual ~SIPrefix();
	static QString createCursorQuery() {
		return QString("SELECT LOGIC.GET_ALL_SI_PREFIXES('foobar');");
	}
	static QString fetchAllQuery() {
		return QString("FETCH ALL IN foobar;");
	}
	static QString closeCursorQuery() {
		return QString("CLOSE foobar;");
	}
	qulonglong id() const {
		return id_;
	}
	QString name() const {
		return name_;
	}
	QString code() const {
		return code_;
	}
	QString symbol() const {
		return symbol_;
	}
	qreal factor() const {
		return factor_;
	}
	QString description() const {
		return description_;
	}
	QString toString() const {
		return QObject::tr("Name: %1, Symbol: %2, Code: %3, Factor: %4")
		.arg(name())
		.arg(symbol())
		.arg(code())
		.arg(factor());
	}
	void setId(const qulonglong& id) {
		id_ = id;
	}
	void setName(const QString& n) {
		name_ = n;
	}
	void setCode(const QString& c) {
		code_ = c;
	}
	void setSymbol(const QString& s) {
		symbol_ = s;
	}
	void setFactor(const qreal& r) {
		factor_ = r;
	}
	void setDescription(const QString& d) {
		description_ = d;
	}
private:
	qulonglong id_;
	QString name_;
	QString code_;
	QString symbol_;
	qreal factor_;
	QString description_;
};

#endif SI_PREFIX_H
