#include "Map.h"
#define WIDTH 20
#define HEIGHT 20
static int map_Width;
static int map_Height;
enum Select
{
	Start = 1,
	Replay,
	Setting,
	Exit
};

Map::Map()
{
	MapDraw::GameMapDraw(0, 0, map_Width, map_Height);
}


void Map::UIDraw()
{
		int Select;
		MapDraw::DrawMidText("1.게임 시작", map_Width, 5);
		MapDraw::DrawMidText("2.Replay", map_Width, 7);
		MapDraw::DrawMidText("3.게임 설정", map_Width, 9);
		MapDraw::DrawMidText("4.종료", map_Width, 11);
		MapDraw::BoxDraw(14, 13, 7, 3);
		MapDraw::gotoxy(map_Width, 14);
		cin >> Select;
		switch (Select)
		{
			case Start:
				MainGame game;
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
