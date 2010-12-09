#include <Mapper.h>

#include <QtGui/QApplication>

#include <App.h>

Mapper::Mapper(QObject* p, const QString& selectAllCursorName,
		const QString& selectAllProcedureName) :
	QObject(p), selectAllCursorName_(selectAllCursorName),
			selectAllProcedureName_(selectAllProcedureName) {

	selectAllOpenId_ = nextQueryId();
	fetchAllId_ = nextQueryId();
	closeCursorId_ = nextQueryId();
}

Mapper::~Mapper() {
}

void Mapper::onQueryCompleted(const TypedQuery& q) {
}

qlonglong Mapper::nextQueryId() {
	return (qobject_cast<App*>(QApplication::instance()))->nextQueryId();
}