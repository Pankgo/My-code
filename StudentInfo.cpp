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
			std::cout << "�г� �Է� : ";
			std::cin >> classnumber;
			if (classnumber > ClassMax)
			{
				std::cout << "4�г� �̻��� �����ϴ�.";
				continue;
			}
			std::cout << "�л� �̸� �Է� : ";
			std::cin >> name;
			std::cout << "���� (0) ���� (1) : ";
			switch (select)
			{
			case Male:
				gender = "����";
				break;
			case Female:
				gender = "����";

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
	std::cout << "�̸� : " << name;
	std::cout << "Ŭ���� : " << classnumber;
	std::cout << "��ȣ : " << number;
	std::cout << "�� : " << gender;

}