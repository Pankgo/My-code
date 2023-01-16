#pragma once
#include"Mecro.h"
#include"MapDraw.h"
#include"conio.h"

class Game
{
	const string p1 = "A";
	const string p2 = "B";
	int p1_back = 5;//¹«¸£±â È½¼ö
	int p2_back = 5;//¹«¸£±â È½¼ö
	int turn = 1;
	int start_y = 20;
	int start_x = 20;
	int* p1_stone = new int[100];
public:

	void Mainplay();
	Game();
	void 




};