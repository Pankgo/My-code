#pragma once
#include "Master.h"

class Observer {

public:
	virtual ~Observer() {}
	virtual void UpdateInfo(std::string _news, std::string _date) abstract; //정보 업데이트 함수
	virtual void PrintInfo() abstract; //정보 업데이트 함수

};

class customer : public Observer {

	std::string name;
	std::string news;
	std::string date;
public:
	void UpdateInfo()
	{
		std::cout << "이름 입력 ";
		std::cin >> name;
	}
	void UpdateInfo(std::string _news, std::string _date)
	{
		news = _news;
		date = _date;
	}

	void PrintInfo()
	{
		std::cout << name << " " << news << std::endl;
	}



}; 