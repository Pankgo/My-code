#include "Function.h"

int Function::Money(int time)
{
	return(time * 7500);//�Ű������� �ٷ� return�� ���� �� ����
}
int Function::Sum(int max)
{
	int sum=0;
	for (int i = 1; i <= max; i++)//�Ű� ������ �̿��� ������ ���Ѵ�
	{
		sum += i;
	}
	return sum;
}
void Function::Dan(int gMin, int gMAX)
{
	for (int i = 1;i<10; i++)//ù��° �ݺ����� 1~9���� ���� ���� ǥ��
	{
		for (int y = gMin; y <= gMAX; y++)//�ι�° �ݺ����� �ּڰ�~�ִ� ��ŭ ������ ������� �����ش�.
		{
			std::cout << y << " x " << i << " = " << y * i<<" ";
		}
		printf("\n");
	}
}
