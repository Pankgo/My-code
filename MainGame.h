#pragma once
#include"Mecro.h"
#include"MapDraw.h"
#include"conio.h"
#include"GameSet.h"
#include"PlayerInfo.h"

class MainGame
{
	int player1[75][75] = { 0, };
	int player2[75][75] = { 0, };
	
public:

	PlayerInfo *p1;
	PlayerInfo *p2;
	void Mainplay(int playerType);
	void CMove(PlayerInfo *A,int move,int character);
	MainGame();
	
};