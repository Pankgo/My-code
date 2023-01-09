#include "Function.h"

int Function::Money(int time)
{
	return(time * 7500);//매개변수로 바로 return을 통해 값 도출
}
int Function::Sum(int max)
{
	int sum=0;
	for (int i = 1; i <= max; i++)//매개 변수를 이용해 총합을 구한다
	{
		sum += i;
	}
	return sum;
}
void Function::Dan(int gMin, int gMAX)
{
	for (int i = 1;i<10; i++)//첫번째 반복문은 1~9까지 곱할 숫자 표현
	{
		for (int y = gMin; y <= gMAX; y++)//두번째 반복문은 최솟값~최댓값 만큼 구구단 결과값을 보여준다.
		{
			std::cout << y << " x " << i << " = " << y * i<<" ";
		}
		printf("\n");
	}
}
