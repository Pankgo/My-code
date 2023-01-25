#include "Map.h"
#define WIDTH 20
#define HEIGHT 20
static int map_Width;
static int map_Height;
enum Select
{
	End,
	Start,
	Replay,
	Setting,
	Exit
};
enum Player
{
	N,
	F,
	S
};
enum Turn
{
	TStart=1,
	TEnd = 0
};

Map::Map()
{

	
}


void Map::UIDraw()
{
	int Game = Start;
	int turn = F;
	int Select;
	int setting;
	while (1)
	{
		system("cls");
		stoneList = vector<Point>();
		MapDraw::GameMapDraw(0, 0, Map::m_Width, Map::m_Height);
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

			while (Game != End)
			{
				MapDraw::GameMapDraw(0, 0, Map::m_Width, Map::m_Height);
				MapDraw::StoneDraw(stoneList);
				MainGame::Mainplay(turn, &p1, &p2, &stoneList);
				if (stoneList.size() >= 9)
				{
					switch (Select = MainGame::WinCheck(stoneList, wincheck, retMW(), retMH()))
					{
					case F:
						cout << "첫번째 플레이어가 이겼습니다.";
						Game = End;
						break;
					case S:
						cout << "두번째 플레이어가 이겼습니다.";
						Game = End;
						break;
					case N:
						break;
					}
				}
				if (turn == F && p1.RetTurn() == TEnd)
				{
					turn = S;
					wincheck[p1.retPx()][p1.retPy()] = 1;
					p1.StartTurn();
				}
				else if (turn == S && p2.RetTurn() == TEnd)
				{
					turn = F;
					wincheck[p2.retPx()][p2.retPy()] = 2;
					p2.StartTurn();
				}

			}
			Game = Start;
			if (Select == F)
			{
				turn = S;
			}
			else
			{
				turn = F;
			}
			system("pause");
			break;
		case Replay:
			break;
		case Setting:
			while (1)
			{
				cout << "1.맵 설정\n";
				cout << "2.플레이어 컨트롤스톤 설정\n";
				cout << "3.플레이어 스톤 설정\n";
				cout << "4.종료";
				cin >> setting;
				switch (setting)
				{
				case 1:
					system("cls");
					break;
				case 2:
					break;
				case 3:
					break;
				case 4:
					break;
				}

			}
		}
	}
}
void Set_Map()
{
	cout << "맵 가로 설정 (20~90)";
	cin >> Map::m_Width;
	cout << "맵 세로 설정 (20~45)";
	cin >> Map::m_Height;
}
void Set_PlayerMouse()
{
	int select;
	cout << "1 .○ ●";	
	cout << "2.♡ ♥";
	cout << "3.☞ ☜";
	cout << "4.① ②";
	cin >> select;
	switch (select)
	{
	case 1:
		p1.SetMouse("○");
		p2.SetMouse("●");
		break;
	case 2:
		p1.SetMouse("♡");
		p2.SetMouse("♥");
		break;
	case 3:
		p1.SetMouse("☞");
		p2.SetMouse("☜");
		break;
	case 4:
		p1.SetMouse("①");
		p2.SetMouse("②");
		break;
	}
}
void Set_PlayerStone()
{
	int select;
	cout << "1 .○ ●";
	cout << "2.♡ ♥";
	cout << "3.☏ ☎";
	cout << "4.① ②";
	cin >> select;
	switch (select)
	{
	case 1:
		p1.SetStone("○");
		p2.SetStone("●");
		break;
	case 2:
		p1.SetStone("♡");
		p2.SetStone("♥");
		break;
	case 3:
		p1.SetStone("☞");
		p2.SetStone("☜");
		break;
	case 4:
		p1.SetStone("①");
		p2.SetStone("②");
		break;
	}
}



