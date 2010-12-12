#include <private/PrimaryKeyConstraintData.h>

#include <QtCore/QStringList>

PrimaryKeyConstraintData::PrimaryKeyConstraintData(const QString& name) :
	Base(name) {
}

PrimaryKeyConstraintData::PrimaryKeyConstraintData(const PrimaryKeyConstraintData& other) :
	Base(other), _cols(other._cols) {
}

PrimaryKeyConstraintData::~PrimaryKeyConstraintData() {
}

QStringList PrimaryKeyConstraintData::columnNames() const {
	QStringList ret;
	for (TableColumnList::const_iterator i = _cols.begin(); i != _cols.end(); i++) {
		ret.append((*i)->name());
	}
	return ret;
}

void PrimaryKeyConstraintData::appendColumn(TableColumn* col) {
	_cols.append(col);
}