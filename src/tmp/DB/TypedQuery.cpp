#include "TypedQuery.h"

TypedQuery::TypedQuery(const QString& sql, const qlonglong& qid) :
	sql_(sql), qid_(qid) {
}

TypedQuery::~TypedQuery() {
}
