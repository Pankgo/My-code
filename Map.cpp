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
enum Player
{
	F = 1,
	S
};
enum Turn
{
	TStart=1,
	TEnd = 0
};

Map::Map()
{
	MapDraw::GameMapDraw(0, 0, Map::m_Width, Map::m_Height);
	stoneList = vector<Point>();
	//stoneStack = std::stack<Point>();
	//stoneList.rbegin
}


void Map::UIDraw()
{
		int turn = F;
		int Select;
		MapDraw::DrawMidText("1.게임 시작", m_Width, 5);
		MapDraw::DrawMidText("2.Replay", m_Width, 7);
		MapDraw::DrawMidText("3.게임 설정", m_Width, 9);
		MapDraw::DrawMidText("4.종료", m_Width, 11);
		MapDraw::BoxDraw(14, 13, 7, 3);
		MapDraw::gotoxy(m_Width, 14);
		cin >> Select;
		switch (Select)
		{
			case Start:
				while (1)
				{
					MapDraw::GameMapDraw(0, 0, Map::m_Width, Map::m_Height);
					MapDraw::StoneDraw(stoneList);
					MainGame::Mainplay(turn, &p1, &p2,stoneList);
					if (turn == F && p1.RetTurn() == TEnd)
					{
						turn = S;
						p1.RetTurn() == TStart;
					}
					else if(turn == S && p2.RetTurn() == TEnd)
					{
						turn = F;
						p2.RetTurn() == TEnd;
					}

				}

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
