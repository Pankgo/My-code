#include "Block.h"

Block::Block()
{
	shape[OutWall] = "¢Ë";
	shape[InWall] = " ¢Ç";
	shape[Player] = "¢Â";
	shape[SnakeTail_Point] = "¢¾";
}

void Block::DrawMap(int map_x, int map_y)
{
	for (int y = 0; y < map_y; y++)
	{
		for (int x = 0; x < map_x * 2; x++)
		{
			if (y == 0 || y == map_y - 1)
			{
				DrawBlock(OutWall, x, y);
			}
		}
	}
}

void Block::DrawBlock(int check,int x, int y)//
{
	gotoxy(x*2, y);
	switch (check)
	{
	case OutWall:
		cout << shape[OutWall];
		break;
	case InWall:
		cout << shape[InWall];
		break;
	case Player:
		cout << shape[Player];
		break;
	case SnakeTail_Point:
		cout << shape[SnakeTail_Point];
		break;
	}
}

void Block::DelBlock(int x, int y)
{
	gotoxy(x, y);
	cout << " ";
}
