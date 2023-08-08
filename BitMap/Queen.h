#pragma once

#include "pieces.h"

class Queen : public _Chess
{
public:
	Queen() {};
	virtual std::vector<POINT>  SetMove(std::vector<_Chess*>pieces) override
	{

		std::vector<POINT> moveable;

		int curY = GetY();
		int curX = GetX();

		bool down = true; // �����¿�
		bool up = true;
		bool right = true;
		bool left = true;

		bool left1 = true; // �밢��
		bool left2 = true;
		bool right1 = true;
		bool right2 = true;


		for (int count = 1; count < 8; count++)
		{
			if (CheckPieces(curX, curY + count * 80, pieces) && down) // ��
			{
				moveable.push_back({ curX - 80 * count, curY + count * 80 });
			}
			else
			{
				down = false;
			}
			if (CheckPieces(curX, curY - count * 80, pieces) && up) // ��
			{
				moveable.push_back({ curX - 80 * count, curY + count * 80 });
			}
			else
			{
				up = false;
			}
			if (CheckPieces(curX + 80 * count, curY, pieces) && right) // ��
			{
				moveable.push_back({ curX - 80 * count, curY + count * 80 });
			}
			else
			{
				right = false;
			}
			if (CheckPieces(curX - 80 * count, curY, pieces) && left) //��
			{
				moveable.push_back({ curX - 80 * count, curY + count * 80 });
			}
			else
			{
				left = false;
			}

		}



		for (int count = 1; count < 8; count++)
		{
			if (CheckPieces(curX - 80 * count, curY + count * 80, pieces) && left1) // (-,+) �밢��
			{
				moveable.push_back({ curX - 80 * count, curY + count * 80 });
			}
			else
			{
				left1 = false;
			}
			if (CheckPieces(curX - 80 * count, curY - count * 80, pieces) && left2) // (-,-) �밢��
			{
				moveable.push_back({ curX - 80 * count, curY + count * 80 });
			}
			else
			{
				left2 = false;
			}
			if (CheckPieces(curX + 80 * count, curY - count * 80, pieces) && right1) // (+,-) �밢��
			{
				moveable.push_back({ curX - 80 * count, curY + count * 80 });
			}
			else
			{
				right1 = false;
			}
			if (CheckPieces(curX + 80 * count, curY + count * 80, pieces) && right2) // (+,+) �밢��
			{
				moveable.push_back({ curX - 80 * count, curY + count * 80 });
			}
			else
			{
				right2 = false;
			}

		}

		return moveable;
	}
};