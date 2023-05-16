#pragma once
#include "Master.h"
#include "Observer.h"
#pragma warning(disable:4996)

class SubJect abstract
{
public:
	virtual ~SubJect() {}
	virtual void AddOb() abstract;//옵저버추가
	virtual void UpdateOb() abstract;//옵저버 정보 업데이트
};

class News : public SubJect
{	
	static News* _news;
	News() {}
	std::string date;
	std::string news;
	std::vector<Observer*> observers;

public :
	static News* get_instance()
	{
		if (NULL == _news) _news = new News;
		return _news;
	}
	std::string currentDateTime() //현재 시간 받는 함수.
	{
		time_t now = time(0); //현재 시간을 time_t 타입으로 저장.
		struct tm tstruct;
		tstruct = *localtime(&now);
		char buf[80];
		strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct); // YYYY-MM-DD.HH:mm:ss

		return buf;
	}
	void AddOb()//옵저버 추가
	{
		customer* _customer = new customer;
		_customer->UpdateInfo();
		observers.push_back(_customer);
	}
	void UpdateOb()//observers 뉴스 날짜 업데이트
	{
		for (std::vector<customer> ::iterator iter = observers.begin(); iter < observers.end(); iter++)
		{
			iter->UpdateInfo(news, date);
		}
	}
	void UpdateNews()//뉴스 정보 업데이트
	{
		std::cout << "새로운 뉴스 입력";
		std::cin >> news;
		date = currentDateTime();
		
	}
	
	void ObInfoPrint()//옵저버 정보 출력함수
	{
		for (std::vector<customer> ::iterator iter = observers->begin(); iter < observers->end(); iter++)
		{
			iter->PrintInfo();
		}
	}

};
News* News::_news = NULL;
