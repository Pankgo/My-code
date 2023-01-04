#include "StudentInfo.h"
#define MAX 10


class StudentManage
{
	StudentInfo student[MAX];
	int studentCount = 0;

public:
	void StudentList(int select);//학생들의 정보를 출력하는데 Select 값에 따라 클래스 순서대로 출력하거나 등록된순서대로 출력
	void EnrollStudent();//학생들의 정보들을 등록
	void Delete(int select);//Select 값에 따라 전체 삭제 또는 마지막 학생 삭제
	void nameSearch(int select);//이름을 통해 학생 검색
	void Search(int select);//클래스를 통해 학생(들) 검색

};