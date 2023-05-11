#pragma once
#include "Master.h"
#include "Observer.h"
class SubJect
{
	static SubJect* subject;
	SubJect();

	std::string date;
	std::string news;
	std::vector<Observer> observers;
public:
	virtual void Update(...) abstract;
	virtual void Print() abstract;


};

SubJect* SubJect::subject = NULL;

class News : public SubJect
{
public :


};