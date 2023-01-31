#include<iostream>
#include<fstream>
#include<string>
using namespace std;
void fun1(int& num1, int& num2)
{
	if (num1 < num2)
	{
		num1 = num2;
	}

}
void fun2(int& num1, int& sum)
{
	int num = num1;
	for (; num <= 100; num += num1)
	{
		sum += num;
	}
}
void fun3(const string& A, string& B)
{
	for (int i = A.size(); i >= 0; i--)
	{
		B += A[i];
	}
}

void main()
{
	int num1, num2, sum = 0;
	string A = " ";
	string B = " ";
	/*cout << "두수를 입력하세요";
	cin >> num1 >> num2;
	fun1(num1, num2);
	cout <<  num1 <<"가 더큽니다.";
	cout << endl << "숫자 하나를 입력하세요";
	cin >> num1;
	fun2(num1,sum);
	cout << num1 << "의 배수의 합 : " << sum;*/
	cout << endl << "숫자를 입력하세요";
	cin >> A;
	fun3(A, B);
	cout << B;
}