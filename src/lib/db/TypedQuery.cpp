#include "TypedQuery.h"

TypedQuery::TypedQuery(const QString& sql, const Queries::QueryId& qid) :
	sql_(sql), qid_(qid) {
}

TypedQuery::~TypedQuery() {
}
