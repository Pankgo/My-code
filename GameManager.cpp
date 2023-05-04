#include "GameManager.h"

void GameManager::StartScreen()//�ʱ�ȭ�� �޴����(���ӽ���, ��ũ ���, ����)
{
	
	system("cls");
	DrawMap.DrawBox(map_width,map_height);
	DrawMap.DrawTextBox(map_width, map_height);
	StartMenu();
	
	switch (DrawMap.MenuSelectCursor(3, 1, startX - 3, startY))
		{
		case Start:
			MainGame();
			break;
		case Rank:
			PrintRank();
			break;
		case End:
			return;
		}
}
bool GameManager::PrintStory(string group[26],int prtstart,int prtend)
{

	if(prtend ==0)
	{
		return false;
	}
	else
	{
		int end=0, start = 0;
		if (prtstart != 0)
		{
			prtstart--;
		}
		prtend--;
		if (PrintStory(group, prtstart, prtend) == true)
		{
			return true;
		}
		end = clock() *0.001;
		while (1)
		{
			start = clock() * 0.001;
			
			if (start - end > 1)
			{
				for (int i = prtstart; i < prtend; i++)
				{
					DrawMap.Drawtext(startX, startY + (i - prtstart), "                                           ", 0);
					DrawMap.Drawtext(startX, startY + (i - prtstart), group[i], 0);
					DrawMap.DrawMidText("��ŵ��ư : S", inboxTextx, inboxTexty);
				}
				break;
			}
			
		}
		if (_kbhit())
			{
				if ('s' == _getch()) return true;
			}
			
	}
		
	
}


void GameManager::Story()//���丮 ���
{
	ifstream load;
	string group[26];
	string line;
	int start = 0, end = 0;
	int count = 0;
	int prtstart = 20, prtend = 25;
	int changey = 0;
	int check = 6;
	load.open("����ġ��_���丮.txt");

	while (!load.eof())
	{
		getline(load, line);
		group[start] = line;
		start++;
	}

	end = clock() / 1000;
	system("cls");		
	DrawMap.DrawBox(map_width, map_height);
	DrawMap.DrawTextBox(map_width, map_height);
	PrintStory(group, prtstart, prtend);
}

void GameManager::MainGame()
{
	int gamepause = 2;
	int timecheck = 0;
	bool checkpause = false;
	string checkword;
	srand(time(NULL));
	string playername = "";
	int stage = 1;
	int life = 7;
	int select;
	char answer[30];
	string word;
	ifstream load;
	load.open("Word.txt");
	int saveitem = 0;//���� �ܾ ��µǴ� ����
	int randnum = 0;
	int starttime = 0, endtime = 0;
	int stagespeed = 1;

	playerInfo.Playerclear();
	DrawMap.DrawBox(map_width, map_height);
	DrawMap.DrawTextBox(map_width, map_height);
	DrawMap.Drawtext(inboxTextx - 4, inboxTexty - 4, "�̸� �Է� ", No);
	DrawMap.gotoxy(inboxTextx, inboxTexty);//������ �̸�, �������� �ʱ�ȭ

	while (1)//���丮 ��� �� �̸� �Է�
	{
		DrawMap.DrawMidText(playername, inboxTextx, inboxTexty);
		if (_kbhit())
		{
			if (wordmanager.InputWord(_getch(), &playername) == false && playername.length() >= 10)
			{
				endtime = clock()*0.001;
				while (1)
				{
					starttime = clock()*0.001;
					DrawMap.DrawMidText("��������!(10������)", inboxTextx, inboxTexty);
					if ((starttime - endtime) > 2)
					{
						DrawMap.DrawMidText("                   ", inboxTextx, inboxTexty);
						playername.clear();
						break;
					}

				}
			}
			else if (wordmanager.InputWord(_getch(), &playername) == true)
			{
				playerInfo.Setname(playername);
				break;
			}
			DrawMap.DrawMidText("                ", inboxTextx, inboxTexty);
		}
	}

	Story();

	system("cls");
	DrawMap.DrawBox(map_width, map_height);
	DrawMap.gotoxy(inboxTextx, inboxTexty);
	DrawMap.DrawTextBox(map_width, map_height);
	DrawMap.gotoxy(inboxTextx, inboxTexty);
	endtime = clock() / 1000;
	while (life != 0)//������
	{

		starttime = clock() * 0.001;
		if (starttime - endtime > stagespeed && checkpause == false)//�ð������� ������ ���� ���� & �ܾ� ������ ����
		{
			DrawMap.Drawtext(1, map_height, "������", No);
			for (int i = 0; i < playerInfo.getLife(); i++)
			{
				DrawMap.Drawtext(9+i*2, map_height, "��", No);
			}
			DrawMap.Drawtext(map_width, map_height, "��������", No);
			DrawMap.Drawtext(map_width + 8, map_height, to_string(stage), No);
			DrawMap.Drawtext(map_width * 2 - 10, map_height, "����", No);
			DrawMap.Drawtext(map_width * 2 - 5, map_height, to_string(playerInfo.GetPoint()), No);
			if (wordmanager.setwordY(&playerInfo,map_height) == false) break;//���� ���ӿ� ��µǴ� �ܾ� y��ǥ ��ȯ
			wordmanager.PrintWord();//�ܾ����
			DrawMap.DrawTextBox(map_width, map_height);
			DrawMap.DrawMidText(checkword, inboxTextx, inboxTexty);
			wordmanager.SetNewWord();//���ο�ܾ�����
			endtime = clock() / 1000;

		}
		else if (starttime - endtime >= 2 && checkpause == true)//Ư���ܾ� : ���� 2�� ���߱�
		{
			checkpause = false;
			endtime = clock() * 0.001;
		}
		if (_kbhit())
		{
			if (wordmanager.InputWord((char)_getche(), &checkword) == true && wordmanager.Checkword(checkword) == true)
			{
				switch (wordmanager.GetwordSkill(checkword))
				{
				case speedup: //�ܾ� �������� �ӵ�����
					stagespeed -= 0.3;
					break;
				case speeddown: // �ܾ� �������� �ӵ� ����
					stagespeed += 0.3;
					break;
				case doublepoint: // �����ι�ȹ��
					playerInfo.SetPoint(20);
					break;
				case screenclear: // ���� ��µǴ� �ܾ� ����
					wordmanager.AllDel();
					break;
				case gamestop: // �����ð����߱�
					checkpause = true;
					break;
				default:
					playerInfo.SetPoint(10);
				}
				if (playerInfo.GetPoint() == stage * 150)
				{
					stage++;
					stagespeed = 1 / stage;
					playerInfo.SetPoint(-150);
					DrawMap.Drawtext(map_width * 2 - 5, map_height, "       ", No);
				}
				
				checkword.clear();
			}
			DrawMap.DrawMidText( "                ", inboxTextx,inboxTexty);
			DrawMap.DrawMidText(checkword, inboxTextx, inboxTexty);

		}
	}
	wordmanager.AllDel();
	playerInfo.Setstage(stage);
	DrawMap.Drawtext(map_width, map_height + 1, "��������!", No);
	system("pause");
	rank.setPlayerRank(playerInfo);//�÷��̾� ����

}

 void GameManager:: PrintRank()
{
	 rank.SortRank();
	 system("cls");
	 DrawMap.DrawBox(map_width, map_height);
	 rank.PrintRank();
	 system("pause");
}