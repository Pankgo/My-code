#pragma once
#include "Master.h"
#include "Observer.h"
#pragma warning(disable:4996)

class SubJect abstract
{
public:
	virtual ~SubJect() {}
	virtual void AddOb() abstract;//�������߰�
	virtual void UpdateOb() abstract;//������ ���� ������Ʈ
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
	std::string currentDateTime() //���� �ð� �޴� �Լ�.
	{
		time_t now = time(0); //���� �ð��� time_t Ÿ������ ����.
		struct tm tstruct;
		tstruct = *localtime(&now);
		char buf[80];
		strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct); // YYYY-MM-DD.HH:mm:ss

		return buf;
	}
	void AddOb()//������ �߰�
	{
		customer* _customer = new customer;
		_customer->UpdateInfo();
		observers.push_back(_customer);
	}
	void UpdateOb()//observers ���� ��¥ ������Ʈ
	{
		for (std::vector<customer> ::iterator iter = observers.begin(); iter < observers.end(); iter++)
		{
			iter->UpdateInfo(news, date);
		}
	}
	void UpdateNews()//���� ���� ������Ʈ
	{
		std::cout << "���ο� ���� �Է�";
		std::cin >> news;
		date = currentDateTime();
		
	}
	
	void ObInfoPrint()//������ ���� ����Լ�
	{
		for (std::vector<customer> ::iterator iter = observers->begin(); iter < observers->end(); iter++)
		{
			iter->PrintInfo();
		}
	}

};
News* News::_news = NULL;
