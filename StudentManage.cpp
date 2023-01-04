#include "StudentManage.h"

#define create 1 // �л��� ��� ��ų�� ���
#define all 0 // ��ü �л� ������ ������ų�� ���

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
		Last,// ������ �л� ����
		All // ��ü �л� ����
	};
	switch (Select)
	{
		case Last:
			student[studentCount - 1].setStudent(Last);
			std::cout << "������ �л� ����";
			break;
		case All:
			for (int i = 0; i < studentCount; i++)
			{
				student[i].setStudent(Last);
			}
			std::cout << "��ü �л� ����";
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
		std::cout << "�л� �̸��� �Է��ϼ���";
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
			std::cout << "�л��� �������� �ʽ��ϴ�.";
		}
		break;
	case classnum:
		std::cout << "Ŭ������ �Է��ϼ���";
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
			std::cout << "Ŭ������ �������� �ʽ��ϴ�.";
		}
		break;
	}

}
