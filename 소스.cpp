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
	/*cout << "�μ��� �Է��ϼ���";
	cin >> num1 >> num2;
	fun1(num1, num2);
	cout <<  num1 <<"�� ��Ů�ϴ�.";
	cout << endl << "���� �ϳ��� �Է��ϼ���";
	cin >> num1;
	fun2(num1,sum);
	cout << num1 << "�� ����� �� : " << sum;*/
	cout << endl << "���ڸ� �Է��ϼ���";
	cin >> A;
	fun3(A, B);
	cout << B;
}