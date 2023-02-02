#include "Merch.h"

class SnakeInfo
{
	int snake_X, snake_Y;//뱀의 현재 좌표
	char oldDirection; // 뱀의 진행방향

public:
	void Snakemove(char ch);//뱀 동작확인 함수
	void SetSnakePosX( int i)
	{
		snake_X += i;
	}
	void SetSnakePosY( int i)
	{
		snake_Y += i;
	}
	int retPosX()
	{
		return snake_X;
	}
	int retPosY()
	{
		return snake_Y;
	}

};