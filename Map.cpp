#include"Map.h"
#define WIDTH 20
#define HEIGHT 20
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
	p1.SetMouse("○");
	p2.SetMouse("●");
	p1.SetStone("○");
	p2.SetStone("●");
}


void Map::UIDraw()
{
	int Set = Start;
	int Game = Start;
	int turn = F;
	int Select;
	int setting;
	while (1)
	{
		system("cls");
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
			p1.Back(10);
			p2.Back(10);
			p1.Startp();
			p2.Startp();
			stoneList.clear();
			for (int y = 0; y < m_Height; y++)
			{
				for (int x = 0; x < m_Width; x++)
				{
					wincheck[y][x] = 0;
				}
			}
			while (Game != End)
			{
				MapDraw::GameMapDraw(0, 0, Map::m_Width, Map::m_Height);
				cout << endl;
				cout << "플레이어 1 무르기 횟수 : " << p1.RetBack();
				cout << "플레이어 2 무르기 횟수 : " << p2.RetBack() << endl;
				cout << "돌놓기 : SpaceBar";
				cout << "무르기 : B";
				MapDraw::StoneDraw(stoneList, p1, p2);
				MainGame::Mainplay(turn, &p1, &p2, &stoneList);
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
				if (stoneList.size() >= 9)
				{
					switch (MainGame::WinCheck(stoneList, wincheck, retMW(), retMH()))
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

			}
			Game = Start;
			system("pause");
			break;
		case Replay:
			break;
		case Setting:
			Set = Start;
			while (Set != End)
			{
				system("cls");
				cout << "1.맵 설정\n";
				cout << "2.플레이어 컨트롤스톤 설정\n";
				cout << "3.플레이어 스톤 설정\n";
				cout << "4.종료";
				cin >> setting;
				switch (setting)
				{
				case 1:
					SetMap();//맵넓이, 높이 설정
					break;
				case 2:
					SetPlayerMouse();//플레이어 마우스 설정
					break;
				case 3:
					SetPlayerStone();//플레이어 스톤 설정
					break;
				case 4:
					Set = End;
					break;
				}

			}
			break;
		}
	}
}
void Map::SetMap()
{
	cout << "맵 가로 설정 (20~90)";
	cin >> Map::m_Width;
	cout << "맵 세로 설정 (20~45)";
	cin >> Map::m_Height;
}
void Map::SetPlayerMouse()
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
		Map::p1.SetMouse("○");
		Map::p2.SetMouse("●");
		break;
	case 2:
		Map::p1.SetMouse("♡");
		Map::p2.SetMouse("♥");
		break;
	case 3:
		Map::p1.SetMouse("☞");
		Map::p2.SetMouse("☜");
		break;
	case 4:
		Map::p1.SetMouse("①");
		Map::p2.SetMouse("②");
		break;
	}
}
void Map::SetPlayerStone()
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
		Map::p1.SetStone("○");
		Map::p2.SetStone("●");
		break;
	case 2:
		Map::p1.SetStone("♡");
		Map::p2.SetStone("♥");
		break;
	case 3:
		Map::p1.SetStone("☞");
		Map::p2.SetStone("☜");
		break;
	case 4:
		Map::p1.SetStone("①");
		Map::p2.SetStone("②");
		break;
	}
}
Map::~Map() {}



