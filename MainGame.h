#pragma once
#include"Mecro.h"
#include"MapDraw.h"
#include"conio.h"
#include"PlayerInfo.h"
#include"Map.h"

class MainGame
{
	
	
public:

	void Mainplay(int playerType,PlayerInfo *A, PlayerInfo *B);
	void CMove(PlayerInfo *A,int move);
	MainGame();
	
};