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
	static int WinCheck(vector<Point>stoneList,int wincheck[45][90],int x,int y);
	static int WinRightCheck(int y, int x, int wincheck[45][90],int sequence);
	static int WinLeftCheck(int y, int x, int wincheck[45][90],int sequence);
	static int WinRightDiagonalCheck(int y, int x, int wincheck[45][90],int sequence);
	static int WinLeftDiagonalCheck(int y, int x, int wincheck[45][90],int sequence);

	MainGame();
	
};