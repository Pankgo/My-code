#include "Merch.h"

enum shape
{
	OutWall,
	InWall,
	Player,
	SnakeTail_Point
};

class Block
{
	 static string shape[4];// �� = �ܰ���, �� = ���κ�,�� = �÷��̾�콺, �� = ����Ʈ & �첿��


public :
	Block();
	void CheckCrash();//���浹Ȯ��
	void DelBlock(int x, int y);// �� �����
	void DrawBlock(int check,int x, int y);//�� ���� �÷��̾�, ���� �� �׸���
	void DrawMap(int map_x,int map_y);//�ʱ׸���;
	void gotoxy(int x, int y)//��ǥ����
	{
		COORD pos = { x,y };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
	}




};