#include "pieces.h"
#pragma once


class Queen : public _Chess
{
	struct xy {
		int x, y;
		bool pass = true;
	};

	std::vector<xy> queen;
public:
	Queen() {};
	bool SetMove(Tiles tiles[64], std::vector<_Chess*>pieces) override
	{
		int curY = GetY();//현재 퀸의 x좌표
		int curX = GetX();//현재 퀸의 y좌표

		xy newxy;



		for(int x =0; x<8;x++)
		{

		}

		for (int y = 0; y < 8; y++)
		{

		}


		return true;
		//대각선 타일 선정
		// 십자가 타일선정
	}
};