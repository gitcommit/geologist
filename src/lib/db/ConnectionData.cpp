#include "ConnectionData.h"

ConnectionData::ConnectionData(const QString& host,
			       const QString& port, const QString& db, const QString& login,
			       const QString& pass, const bool& create, const bool& drop,
			       const bool& debug) :
  host_(host), port_(port), db_(db), login_(login), pass_(pass),
  drop_(drop), create_(create), debug_(debug) {
}

ConnectionData::~ConnectionData() {
}
