#pragma once
#include "Master.h"
#include "DrawMap.h"


enum Menu {

	Start =1,
	Rank,
	End
};

class GameManager
{
	DrawMap DrawMap;//전체적인 게임배경 그리는 클래스
	int map_width = 60, map_height = 30;//게임의 전체적인 x,y
	int startX = map_width - 13;
	int startY = 10;
	int inboxTextx = map_width - 5, inboxTexty = map_height / 2 + 7;//박스안의 텍스트 입력 위치
public:
	void StartScreen();
	void MainGame();
	void PrintRank();
	void StartMenu()
	{
		int startX = map_width - 13;
		int startY = 10;

		DrawMap.DrawMidText(startX,startY , "1.게임 시작");
		DrawMap.DrawMidText(startX, startY+1, "2.랭크 출력");
		DrawMap.DrawMidText(startX, startY+2, "3.종료");

	}
};
	