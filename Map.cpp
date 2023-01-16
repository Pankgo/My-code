#include "Map.h"
#define WIDTH 20
#define HEIGHT 20
enum Select
{
	Start = 1,
	Replay,
	Setting,
	Exit
};

Map::Map()
{
	MapDraw::GameMapDraw(0, 0, WIDTH, HEIGHT);
}


void Map::UIDraw()
{
		int Select;
		MapDraw::DrawMidText("1.게임 시작", WIDTH, 5);
		MapDraw::DrawMidText("2.Replay", WIDTH, 7);
		MapDraw::DrawMidText("3.게임 설정", WIDTH, 9);
		MapDraw::DrawMidText("4.종료", WIDTH, 11);
		MapDraw::BoxDraw(14, 13, 7, 3);
		MapDraw::gotoxy(WIDTH, 14);
		cin >> Select;
		switch (Select)
		{
			case Start:
				break;
			case Replay:
				break;
			case Setting:
				break;
			case Exit:
				return;
		}

}

Map::~Map()
{
}
