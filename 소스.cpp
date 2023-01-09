#include "Function.h"


void main()
{
	enum mainSelect//메인화면 
	{
		money=1,
		allsum,
		guguDan
	};
	enum noYes // No, Yes 설정
	{
		No,
		Yes
	};
	int main_select;
	int noYes_select;
	Function con;
	while (1)
	{
		system("cls");
		std::cout << "1. 임금 계산" << std::endl;
		std::cout << "2. 총합 계산" << std::endl;
		std::cout << "3. 구구단" << std::endl;
		std::cout << "선택 : ";
		std::cin >> main_select;
		std::cout << "숫자를 설정하실건가요?(No<0>,Yes<1>)";
		std::cin >> noYes_select;
		system("cls");
		switch (main_select)
		{
		case money:
			if (noYes_select == No)
			{
				std::cout << "일급 : " << con.Money();//return으로 결과값 도출(설정을 안할경우 디폴트 매개변수로 보냄)
			}
			else
			{
				int time;
				std::cout << "시간 설정 :";
				std::cin >> time;
				std::cout << "일급 : " << con.Money(time);//return으로 결과값 도출
			}
			break;
		case allsum:
			if (noYes_select == No)
			{
				std::cout << "총합 : " << con.Sum();//return으로 결과값 도출(설정을 안할경우 디폴트 매개변수로 보냄)
			}
			else
			{
				int maxNum;
				std::cout << "최댓값  설정 :";
				std::cin >> maxNum;
				std::cout << "총합 : " << con.Sum(maxNum);//return으로 결과값 도출
			}
			break;
		case guguDan:
			if (noYes_select == No)
			{
				con.Dan();//매개변수로 보내 구구단 페이지를 보여준다
			}
			else
			{
				int maxGNum;
				int minGNum;
				std::cout << "최댓값  설정(9이하) :";
				std::cin >> maxGNum;
				std::cout << "최솟값  설정(2이상) :";
				std::cin >> minGNum;
				con.Dan(minGNum,maxGNum);//함수로 매개 변수를 보내 구구단페이지를  보여준다
			}
			break;
		default :
				return;
		}
		system("pause");
	}

}
