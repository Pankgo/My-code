#include "Function.h"
#include <cmath>
#include <algorithm>

int Function::Pow_Alpabet(int a, int b)//pow함수를 이용하여 리턴
{
	return(std::pow(a, b));
}
int Function::Pow_Alpabet(char a, int b)//문자 + 숫자
{
	return(a + b);
}
void Function::StringFunc(std::string a)//반복문을 이용하여 거꾸로 출력
{
	for (int i = a.size(); i>=1; i--)
	{
		std::cout << a[i-1];
	}
	std::cout << std::endl;
}
void Function::StringFunc(std::string a, std::string b)//문자열+문자열 처리
{
	std::cout << a + b << std::endl;
}

void Function::Sort(int arr[5])//sort함수(오름차순 기본)으로 정렬
{
	std::sort(arr, arr + 5);
	for (int i = 0; i < 5; i++)
	{
		std::cout << arr[i]<<" ";
	}
}

void Function::Sort(std::string a)//sort함수 이용한뒤 비교함수를 넣어 정렬
{
	std::sort(a.begin(), a.end(), std::greater<int>());
	std::cout << a;
}
void Function::Menu()
{
	int num1, num2;
	char A;
	int arr[5];
	std::string str1, str2;
	std::cout << "1.1 두 정수 입력 : ";
	std::cin >> num1, std::cin >> num2;
	std::cout<<Pow_Alpabet(num1, num2)<<std::endl;;
	std::cout << "1.2 문자와 숫자 입력 입력 : ";
	std::cin >> A, std::cin >> num1;
	std::cout<<char(Pow_Alpabet(A, num1))<<std::endl;
	std::cout << "2.1 한개의 문자열 입력 : ";
	std::cin >> str1;
	StringFunc(str1);
	std::cout << "2.2 두개의 문자열 입력 : ";
	std::cin >> str1, std::cin >> str2;
	StringFunc(str1, str2);
	std::cout << "3.1 5개의 숫자 입력 : ";
	for (int i = 0; i < 5; i++)
	{
		std::cin >> arr[i];
	}
	Sort(arr);
	std::cout << "\n3.2 5개의 문자 입력 : ";
	std::cin >> str1;
	Sort(str1);


}
