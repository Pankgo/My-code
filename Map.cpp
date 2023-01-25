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
	p1.SetMouse("��");
	p2.SetMouse("��");
	p1.SetStone("��");
	p2.SetStone("��");
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
		MapDraw::DrawMidText("1.���� ����", m_Width, 5);
		MapDraw::DrawMidText("2.Replay", m_Width, 7);
		MapDraw::DrawMidText("3.���� ����", m_Width, 9);
		MapDraw::DrawMidText("4.����", m_Width, 11);
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
				cout << "�÷��̾� 1 ������ Ƚ�� : " << p1.RetBack();
				cout << "�÷��̾� 2 ������ Ƚ�� : " << p2.RetBack() << endl;
				cout << "������ : SpaceBar";
				cout << "������ : B";
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
						cout << "ù��° �÷��̾ �̰���ϴ�.";
						Game = End;
						break;
					case S:
						cout << "�ι�° �÷��̾ �̰���ϴ�.";
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
				cout << "1.�� ����\n";
				cout << "2.�÷��̾� ��Ʈ�ѽ��� ����\n";
				cout << "3.�÷��̾� ���� ����\n";
				cout << "4.����";
				cin >> setting;
				switch (setting)
				{
				case 1:
					SetMap();//�ʳ���, ���� ����
					break;
				case 2:
					SetPlayerMouse();//�÷��̾� ���콺 ����
					break;
				case 3:
					SetPlayerStone();//�÷��̾� ���� ����
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
	cout << "�� ���� ���� (20~90)";
	cin >> Map::m_Width;
	cout << "�� ���� ���� (20~45)";
	cin >> Map::m_Height;
}
void Map::SetPlayerMouse()
{
	int select;
	cout << "1 .�� ��";	
	cout << "2.�� ��";
	cout << "3.�� ��";
	cout << "4.�� ��";
	cin >> select;
	switch (select)
	{
	case 1:
		Map::p1.SetMouse("��");
		Map::p2.SetMouse("��");
		break;
	case 2:
		Map::p1.SetMouse("��");
		Map::p2.SetMouse("��");
		break;
	case 3:
		Map::p1.SetMouse("��");
		Map::p2.SetMouse("��");
		break;
	case 4:
		Map::p1.SetMouse("��");
		Map::p2.SetMouse("��");
		break;
	}
}
void Map::SetPlayerStone()
{
	int select;
	cout << "1 .�� ��";
	cout << "2.�� ��";
	cout << "3.�� ��";
	cout << "4.�� ��";
	cin >> select;
	switch (select)
	{
	case 1:
		Map::p1.SetStone("��");
		Map::p2.SetStone("��");
		break;
	case 2:
		Map::p1.SetStone("��");
		Map::p2.SetStone("��");
		break;
	case 3:
		Map::p1.SetStone("��");
		Map::p2.SetStone("��");
		break;
	case 4:
		Map::p1.SetStone("��");
		Map::p2.SetStone("��");
		break;
	}
}
Map::~Map() {}



