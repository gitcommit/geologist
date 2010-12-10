#ifndef APPDBMODEL_H_
#define APPDBMODEL_H_

#include <DbModel.h>

class AppDbModel : public DbModel {
	Q_OBJECT
public:
	AppDbModel(QObject* p = 0, const QString& name = QString::null);
	virtual ~AppDbModel();
private:
	void configure();
};

#endif /*APPDBMODEL_H_*/
