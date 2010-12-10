#ifndef APPDBMODEL_H_
#define APPDBMODEL_H_

#include <DbModel.h>

class AppDbModel : public DbModel {
public:
	AppDbModel(const QString& name = QString::null);
	virtual ~AppDbModel();
private:
	AppDbModel(const AppDbModel& other) {} 
	void configure();
};

#endif /*APPDBMODEL_H_*/
