#include <iostream>
#define MAX 100



class Function
{
public:
	int Pow_Alpabet(int a, int b);//숫자처리
	int Pow_Alpabet(char a, int b);//매개변수만큼 문자에서 더함
	void StringFunc(std::string a);//거꾸로 출력
	void StringFunc(std::string a, std::string b);//문자끼리 더함
	void Sort(int arr[5]);//오름차순정렬(숫자)
	void Sort(std::string a);//내림차순정렬(문자열)
	void Menu();
};