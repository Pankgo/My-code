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
	 static string shape[4];// ▦ = 외곽벽, ▤ = 내부벽,◈ = 플레이어마우스, ♥ = 포인트 & 뱀꼬리


public :
	Block();
	void CheckCrash();//벽충돌확인
	void DelBlock(int x, int y);// 블럭 지우기
	void DrawBlock(int check,int x, int y);//맵 안의 플레이어, 꼬리 등 그리기
	void DrawMap(int map_x,int map_y);//맵그리기;
	void gotoxy(int x, int y)//좌표설정
	{
		COORD pos = { x,y };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
	}




};