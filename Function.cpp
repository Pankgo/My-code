#include "Function.h"
#include <cmath>
#include <algorithm>

int Function::Pow_Alpabet(int a, int b)//pow�Լ��� �̿��Ͽ� ����
{
	return(std::pow(a, b));
}
int Function::Pow_Alpabet(char a, int b)//���� + ����
{
	return(a + b);
}
void Function::StringFunc(std::string a)//�ݺ����� �̿��Ͽ� �Ųٷ� ���
{
	for (int i = a.size(); i>=1; i--)
	{
		std::cout << a[i-1];
	}
	std::cout << std::endl;
}
void Function::StringFunc(std::string a, std::string b)//���ڿ�+���ڿ� ó��
{
	std::cout << a + b << std::endl;
}

void Function::Sort(int arr[5])//sort�Լ�(�������� �⺻)���� ����
{
	std::sort(arr, arr + 5);
	for (int i = 0; i < 5; i++)
	{
		std::cout << arr[i]<<" ";
	}
}

void Function::Sort(std::string a)//sort�Լ� �̿��ѵ� ���Լ��� �־� ����
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
	std::cout << "1.1 �� ���� �Է� : ";
	std::cin >> num1, std::cin >> num2;
	std::cout<<Pow_Alpabet(num1, num2)<<std::endl;;
	std::cout << "1.2 ���ڿ� ���� �Է� �Է� : ";
	std::cin >> A, std::cin >> num1;
	std::cout<<char(Pow_Alpabet(A, num1))<<std::endl;
	std::cout << "2.1 �Ѱ��� ���ڿ� �Է� : ";
	std::cin >> str1;
	StringFunc(str1);
	std::cout << "2.2 �ΰ��� ���ڿ� �Է� : ";
	std::cin >> str1, std::cin >> str2;
	StringFunc(str1, str2);
	std::cout << "3.1 5���� ���� �Է� : ";
	for (int i = 0; i < 5; i++)
	{
		std::cin >> arr[i];
	}
	Sort(arr);
	std::cout << "\n3.2 5���� ���� �Է� : ";
	std::cin >> str1;
	Sort(str1);


}
