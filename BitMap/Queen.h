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
		int curY = GetY();//���� ���� x��ǥ
		int curX = GetX();//���� ���� y��ǥ

		xy newxy;



		for(int x =0; x<8;x++)
		{

		}

		for (int y = 0; y < 8; y++)
		{

		}


		return true;
		//�밢�� Ÿ�� ����
		// ���ڰ� Ÿ�ϼ���
	}
};