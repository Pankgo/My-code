#pragma once
#include "Master.h"
#include "DrawMap.h"

class GameManager
{
	DrawMap DrawMap;//전체적인 게임배경 그리는 클래스


public:
	void StartScreen();
	void Game();
	void PrintRank();
};
	