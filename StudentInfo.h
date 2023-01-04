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
	std::string _searchName = name; // studentmange 에서 이름을 통해 학생을 찾을때 사용
	int _searchclass = classnumber; // 마찬가지로 클래스 번호를 통해 학생을 찾을때 사용
	void setStudent(int select);
	void ShowStudentInfo();

};

