#include "Gamemanager.h"

Gamemanager::Gamemanager()
{
	for (int y = 0; y < map_Height; y++)
	{
		for (int x = 0; x < map_Width; x++)
		{

		}
	}
}




void Gamemanager::UIDraw() // ����ȭ��׸���
{
	int select;
	while (1)
	{
		block.DrawMap(map_Width, map_Height);
		Menu();
		cin >> select;
		switch (select)
		{
		case Start:
		{
			GamePlay();
			break;
		}
		case End:
		{
			return;
		}
		}
	}

}

void Gamemanager::MapDraw()//��ü �ʱ׸���
{
	system("cls");
	int check = 0;
	block.DrawMap(map_Width,map_Height);
	while (check == insideWall)
	{
		int randx = rand() % 40;
		int randy = rand() % 30;
		block.DrawBlock(1, randx, randy);
		check++;
	}
}

void Gamemanager::Menu()//���� ȭ�� ���
{
	block.gotoxy(map_Width, map_Height);
	cout << "1. ���� ����\n";
	cout << "2. ���� ����";
}

void Gamemanager::GamePlay()
{
	MapDraw();
	if (kbhit())
	{
		char ch = getch();
		snake.Snakemove(ch);

		
	}
}

void Gamemanager::CheckCrash()
{

}