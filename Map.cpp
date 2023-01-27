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
	None,
	First,
	Second
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
	p1.Back(playerbackchance);
	p2.Back(playerbackchance);
}


void Map::UIDraw()
{
	ofstream save;
	ifstream replay;
	int Set = Start;
	int Game = Start;
	int turn = First;
	int Select;
	int setting;
	while (1)
	{

		system("cls");
		clock_t start = clock();

		vector<Point> ::iterator iter = stoneList.begin();
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
			p1.Back(playerbackchance);
			p2.Back(playerbackchance);
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
				cout << "\n�÷��̾� 1 ������ Ƚ�� : " << p1.RetBack()<<" �÷��̾� 2 ������ Ƚ�� : " << p2.RetBack() << endl;
				cout << "������ : SpaceBar" << " " << "������ : B";
				cout << endl;
				MapDraw::StoneDraw(stoneList, p1, p2);
				MainGame::Mainplay(turn, &p1, &p2, &stoneList);
				if (turn == First && p1.RetTurn() == TEnd)//ó��->�ι�°
				{
					turn = Second;
					wincheck[p1.retPx()][p1.retPy()] = 1;
					p1.StartTurn();
				}
				else if (turn == Second && p2.RetTurn() == TEnd)
				{
					turn = First;
					wincheck[p2.retPx()][p2.retPy()] = 2;
					p2.StartTurn();
				}
				if (stoneList.size() >= 9)
				{
					switch (MainGame::WinCheck(stoneList, wincheck, retMW(), retMH()))
					{
					case First:
						cout << "ù��° �÷��̾ �̰���ϴ�.";
						Game = End;
						break;
					case Second:
						cout << "�ι�° �÷��̾ �̰���ϴ�.";
						Game = End;
						break;
					case None:
						break;
					}
				}

			}
			save.open("stone.txt");
			if (save.is_open())
			{
				//save << stoneList.size() << endl;
				//save << p1.RetMouse() << p2.RetMouse() << endl;
				for (vector<Point>::iterator iter = stoneList.begin(); iter < stoneList.end(); iter++)
				{
					save <<iter->x << " " << iter->y << " " << iter->player << endl;
				}
				save.close();
			}
			Game = Start;
			system("pause");
			break;
		case Replay:
			stoneList.clear();
			MapDraw::GameMapDraw(0, 0, Map::m_Width, Map::m_Height);
			replay.open("stone.txt");
			int x, y, playertype;
			while (!replay.eof())
			{
				replay >> x;
				replay >> y;
				replay >> playertype;
				stoneList.push_back({ playertype, x, y });
			}
			iter = stoneList.begin();
			while (iter != stoneList.end())
			{
					switch (iter->player)
					{
					case First:
						MapDraw::TextDraw(p1.RetStone(), iter->x * 2, iter->y);
						break;
					case Second:
						MapDraw::TextDraw(p2.RetStone(), iter->x * 2, iter->y);
						break;
					}
					iter++;
					Sleep(1000);
			}
			replay.close();
			system("pause");
			break;
		case Setting:
			Set = Start;
			while (Set != End)
			{
				system("cls");
				cout << "1.�� ����\n";
				cout << "2.�÷��̾� ��Ʈ�ѽ��� ����\n";
				cout << "3.�÷��̾� ���� ����\n";
				cout << "4.�÷��̾� ������ Ƚ�� ����\n";
				cout << "5.����";
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
					SetPlayerBackSpace();//�÷��̾� ������ Ƚ�� ����
					break;
				case 5:
					Set = End;
					break;
				}

			}
			break;
		case Exit:
			return;
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
void Map::SetPlayerBackSpace()
{
	cout << "�÷��̾� ������ Ƚ�� ���� : ";
	cin >> playerbackchance;
}
Map::~Map() {}



