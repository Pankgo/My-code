#include "Merch.h"

class SnakeInfo
{
	int snake_X, snake_Y;//���� ���� ��ǥ
	char oldDirection; // ���� �������

public:
	void Snakemove(char ch);//�� ����Ȯ�� �Լ�
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