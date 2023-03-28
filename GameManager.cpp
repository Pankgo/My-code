#include "GameManager.h"

void GameManager::StartScreen()//초기화면 메뉴출력(게임시작, 랭크 출력, 종료)
{
	int select;

	while (1)
	{
	
		DrawMap.DrawBox(map_width,map_height);
		DrawMap.DrawTextBox(map_width, map_height);
		StartMenu();
		DrawMap.gotoxy(inboxTextx,inboxTexty);
		cin >> select;
		switch (select)
		{
		case Start:
			MainGame();
			break;
		case Rank:
			//PrintRank();
			break;
		case End:
			return;
		}
	}
}

void GameManager::MainGame()
{
	system("cls");
	ifstream load;
	string group[26];
	string line;
	int start = 0 , end = 0;
	int del = 0;
	int prt = 0;
	int max = 5;

	load.open("베네치아_스토리.txt");

	while (!load.eof())
	{
		getline(load, line);
		group[start] = line;
		start++;
	}

	end = clock()/1000;
	while (1)
	{
		start = clock()/1000;
		if (start - end > 3)
		{
			system("cls");
			for (int i = 0; i < prt; i++)
			{
				cout<<group[i] <<endl;
			}
			prt++;
			start = 0;

		}
	}
	

	system("pause");

}