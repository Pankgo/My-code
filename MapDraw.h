#pragma once
#include"Mecro.h"
#include <vector>
#include"PlayerInfo.h"
class MapDraw
{
public:

	static void BoxDraw(int Start_x, int Start_y, int Width, int Height)
	{
		for (int y = 0; y < Height; y++)
		{
			gotoxy(Start_x, Start_y + y);
			if (y == 0)
			{
				cout << "┌";
				for (int x = 1; x < Width - 1; x++)
					cout << "─";
				cout << "┐";
			}
			else if (y == Height - 1)
			{
				cout << "└";
				for (int x = 1; x < Width - 1; x++)
					cout << "─";
				cout << "┘";
			}
			else
			{
				cout << "│";
				for (int x = 1; x < Width - 1; x++)
				{
					cout << "  ";
				}
				cout << "│";
			}
		}
		return;
	}
	static void GameMapDraw(int Start_x, int Start_y, int Width, int Height)//스톤검사하여 없을경우 그대로 그리고 있을경우 검은돌인지 하얀돌인지 판별하여 맞는돌출력
	{
		for (int y = 0; y < Height; y++)
		{
			gotoxy(Start_x, Start_y + y);
			if (y == 0)
			{
				cout << "┌";
				for (int x = 1; x < Width - 1; x++)
				{
					cout << "┬";
					
				}
				cout << "┐";
			}
			else if (y == Height - 1)
			{
				cout << "└";
				for (int x = 1; x < Width - 1; x++)
				{
					cout << "┴";
					
				}
				cout << "┘";
			}
			else
			{
				cout << "├";
				for (int x = 1; x < Width - 1; x++)
				{
					cout << "┼";
				}
				cout << "┤";
			}
		}
		return;

	}
	static void DrawPoint(string str, int x, int y)
	{
		gotoxy(x * 2, y);
		cout << str;
		gotoxy(-1, -1);
		return;
	}
	static void DrawMidText(string str, int x, int y)
	{
		if (x > str.size() / 2)
			x -= str.size() / 2;
		gotoxy(x, y);
		cout << str;
		return;
	}
	static void TextDraw(string str, int x, int y)
	{
		gotoxy(x, y);
		cout << str;
	}
	static void ErasePoint(int x, int y)
	{
		gotoxy(x * 2, y);
		cout << "  ";
		gotoxy(-1, -1);
		return;
	}
	MapDraw() {}
	static inline void gotoxy(int x, int y)
	{
		COORD Pos = { x, y };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
	}
	static void StoneDraw(vector<Point> stoneList)//돌그리는 함수
	{
		vector<Point>::iterator iter;
		int checkp1stone = 0;
		int checkp2stone = 0;
		for (iter = stoneList.begin(); iter < stoneList.end(); iter += 1)
		{
			if (iter->player == 1)
			{
				TextDraw("●", iter->x, iter->y);
			}
			else
			{
				TextDraw("○", iter->x, iter->y);
			}

		}
	}

	~MapDraw() {}
};

