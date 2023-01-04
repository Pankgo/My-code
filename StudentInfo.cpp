#include "StudentInfo.h"
#define ClassMax 3

void StudentInfo::setStudent(int select)
{
	enum Gender
	{
		Male = 0,
		Female
	};
	enum Select
	{
		Del,
		create
	};
	switch (select)
	{
	case create : 
		while (1)
		{
			int select;
			std::cout << "학년 입력 : ";
			std::cin >> classnumber;
			if (classnumber > ClassMax)
			{
				std::cout << "4학년 이상은 없습니다.";
				continue;
			}
			std::cout << "학생 이름 입력 : ";
			std::cin >> name;
			std::cout << "남자 (0) 여자 (1) : ";
			switch (select)
			{
			case Male:
				gender = "남자";
				break;
			case Female:
				gender = "여자";

			}
			break;
		}
		break;
	case Del:
		gender = "";
		classnumber = NULL;
		name = "";
		number = NULL;
		break;
	}


}

void StudentInfo::ShowStudentInfo()
{
	std::cout << "이름 : " << name;
	std::cout << "클래스 : " << classnumber;
	std::cout << "번호 : " << number;
	std::cout << "성 : " << gender;

}