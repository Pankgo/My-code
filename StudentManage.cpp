#include "StudentManage.h"

#define create 1 // 학생을 등록 시킬때 사용
#define all 0 // 전체 학생 정보를 삭제시킬때 사용

void StudentManage::EnrollStudent()
{
	student[studentCount].setStudent(create);
	studentCount ++;
}

void StudentManage::StudentList(int Select)
{
	system("cls");
	enum sequence
	{
		classnum,
		enrollnum
	};
	switch (Select)
	{
	case classnum:
		for (int i = 1; i <= 3; i++)
		{
			for (int y = 0; y <= studentCount; y++)
			{
				if (student[y]._searchclass == i)
				{
					student[y].ShowStudentInfo();
				}
			}
		}
		break;
	case enrollnum:
		for (int i = 0; i < studentCount; i++)
		{
			student[i].ShowStudentInfo();
		}
		break;
	}
}
void StudentManage::Delete(int Select)
{
	system("cls");
	enum Del
	{
		Last,// 마지막 학생 삭제
		All // 전체 학생 삭제
	};
	switch (Select)
	{
		case Last:
			student[studentCount - 1].setStudent(Last);
			std::cout << "마지막 학생 삭제";
			break;
		case All:
			for (int i = 0; i < studentCount; i++)
			{
				student[i].setStudent(Last);
			}
			std::cout << "전체 학생 삭제";
			break;
	}
}
void StudentManage::Search(int select)
{
	std::string searchName;
	std::string searchclass;
	bool studentexistence = false;
	bool classexistence = false;
	system("cls");
	enum search
	{
		name,
		classnum
	};
	switch (select)
	{
	case name:
		std::cout << "학생 이름을 입력하세요";
		std::cin >> searchName;
		for (int i = 0; i < studentCount; i++)
		{
			if (searchName == student[i]._searchName)
			{
				student[i].ShowStudentInfo();
				studentexistence = true;
				break;
			}
		}
		if (studentexistence == false)
		{
			std::cout << "학생이 존재하지 않습니다.";
		}
		break;
	case classnum:
		std::cout << "클래스를 입력하세요";
		std::cin >> searchclass;
		for (int i = 0; i < studentCount; i++)
		{
			if (searchclass == student[i]._searchName)
			{
				student[i].ShowStudentInfo();
				classexistence = true;
				break;
			}
		}
		if (classexistence == false)
		{
			std::cout << "클래스가 존재하지 않습니다.";
		}
		break;
	}

}
