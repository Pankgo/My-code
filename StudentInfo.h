#include<iostream>

enum Gender
{
	Male = 0,
	Female
};
enum Class
{
	First = 1,
	Second,
	Third
};

class StudentInfo
{
	std::string name;
	int number;
	int classnumber;
	std::string gender;

public:
	std::string _searchName = name; // studentmange ���� �̸��� ���� �л��� ã���� ���
	int _searchclass = classnumber; // ���������� Ŭ���� ��ȣ�� ���� �л��� ã���� ���
	void setStudent(int select);
	void ShowStudentInfo();

};

