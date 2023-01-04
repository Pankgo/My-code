#include <iostream>
#include "StudentManage.h"

void main()
{
	StudentManage* student = NULL;// studentManage::를 쓸시 경고문이 떠서 인터넷에 해결법 찾아 작성
	enum search
	{
		name,
		classnum
	};
	enum sequence
	{
		_classnum,//클래스 순서대로 출력
		enrollnum // 등록된 순서대로 출력
	};
	enum Del
	{
		Last,// 마지막 학생 삭제
		All // 전체 학생 삭제
	};
	enum Select
	{
		Enroll = 1,
		StudentList_Number,
		StudentList_Class,
		Student_Search,
		Class_Search,
		LastStudentDel,
		AllDel,
		End
	};
	int Select;
	while (1)
	{

		std::cout << "===== 학생관리 프로그램 ======" << std::endl;
		std::cout << "	1. 학생 등록" << std::endl;
		std::cout << "	2. 학생 목록<번호순>" << std::endl;
		std::cout << "	3. 학생 목록<학년순>" << std::endl;
		std::cout << "	4. 학생 검색" << std::endl;
		std::cout << "	5. 학년 검색" << std::endl;
		std::cout << "	6. 마지막 학생 삭제 " << std::endl;
		std::cout << "	7. 학생 전체 삭제" << std::endl;
		std::cout << "	8. 종료" << std::endl;
		std::cout << " 입력 : ";
		std::cin >> Select;
		switch (Select)
		{
		case Enroll:
			student->EnrollStudent();
			break;
		case StudentList_Number:
			student->StudentList(enrollnum);
			break;
		case StudentList_Class:
			student->StudentList(classnum);
			break;
		case Student_Search:
			student->Search(name);
			break;
		case Class_Search:
			student->Search(_classnum);
			break;
		case LastStudentDel:
			student->Delete(Last);
			break;
		case AllDel:
			student->Delete(All);
			break;
		case End:
			return;
		}

	}



}

