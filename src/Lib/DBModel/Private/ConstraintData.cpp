#include <Lib/DBModel/Private/ConstraintData.h>

#include <QtCore/QStringList>

ConstraintData::ConstraintData(const QString& name) :
	Base(name) {
}

ConstraintData::ConstraintData(const ConstraintData& other) :
	Base(other), _cols(other._cols) {
}

ConstraintData::~ConstraintData() {
}

QStringList ConstraintData::columnNames() const {
	QStringList ret;
	for (TableColumnList::const_iterator i = _cols.begin(); i != _cols.end(); i++) {
		ret.append((*i)->name());
	}
	return ret;
}

void ConstraintData::appendColumn(TableColumn* col) {
	_cols.append(col);
}
