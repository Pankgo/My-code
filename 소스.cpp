
#include <iostream>
#define Hour 60
using namespace std;

class TimeUI {
	
		int new_Min =0 ;
		int new_Hour =0;
		int select;
		int hour = 0, min = 0;
		int day = 0;

public:
	int getHour() {
		return hour;
	}
	int getMin() {
		return min;
	}
	int getDay() {
		return day;
	}
	void setHour(int num) {
		new_Hour = num;
	}
	void setMin(int num) {
		new_Min = num;
	}
	TimeUI operator + (TimeUI timeInsert)
	{
		timeInsert.hour += timeInsert.new_Hour;
		timeInsert.min += timeInsert.new_Min;
		timeInsert.day++;
		timeInsert.hour += timeInsert.min / Hour;
		timeInsert.min %= Hour;
		return timeInsert;
	}
	
};



void main()
{
	int select;
	int new_min;
	int new_hour;
	TimeUI time;

	while (1)
	{
		system("cls");
		cout << "�� �ð� " << time.getHour() << " : " << time.getMin() << endl;
		cout << "===== ���� �ð� =====(Day" << time.getDay() << ")" << endl;
		cout << "1. �Է�\n";
		cout << "2. ����\n";
		cin >> select;
		switch (select)
		{
		case 1:
			cout << "�� : ";
			cin >> new_hour;
			cout << "�� : ";
			cin >> new_min;
			time.setHour(new_hour);
			time.setMin(new_min);
			time = time + time;
			break;
		case 2:
			return;
		}
	}
}