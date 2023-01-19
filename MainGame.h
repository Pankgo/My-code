#pragma once
#include"Mecro.h"
#include"MapDraw.h"
#include"conio.h"
#include"PlayerInfo.h"
#include"Map.h"

class MainGame
{
	
	
public:

	static void Mainplay(int playerType,PlayerInfo *A, PlayerInfo *B,vector<Point>*stoneList);
	static void CMove(int playerType,PlayerInfo *A,int move,vector<Point>*stoneList);
	MainGame();
	
};