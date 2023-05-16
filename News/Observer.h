#pragma once
#include "Master.h"

class Observer {

public:
	virtual ~Observer() {}
	virtual void UpdateInfo(std::string _news, std::string _date) abstract; //���� ������Ʈ �Լ�
	virtual void PrintInfo() abstract; //���� ������Ʈ �Լ�

};

class customer : public Observer {

	std::string name;
	std::string news;
	std::string date;
public:
	void UpdateInfo()
	{
		std::cout << "�̸� �Է� ";
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