#include "StudentInfo.h"
#define MAX 10


class StudentManage
{
	StudentInfo student[MAX];
	int studentCount = 0;

public:
	void StudentList(int select);//�л����� ������ ����ϴµ� Select ���� ���� Ŭ���� ������� ����ϰų� ��ϵȼ������ ���
	void EnrollStudent();//�л����� �������� ���
	void Delete(int select);//Select ���� ���� ��ü ���� �Ǵ� ������ �л� ����
	void nameSearch(int select);//�̸��� ���� �л� �˻�
	void Search(int select);//Ŭ������ ���� �л�(��) �˻�

};