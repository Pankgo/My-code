#include "GameManager.h"

void GameManager::StartScreen()//�ʱ�ȭ�� �޴����(���ӽ���, ��ũ ���, ����)
{
	int select;

	while (1)
	{
	
		system("cls");
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
			PrintRank();
			break;
		case End:
			return;
		}
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
		end = clock() / 1000;
		while (1)
		{
			start = clock() / 1000;
			if (start - end > 1)
			{
				for (int i = prtstart; i < prtend; i++)
				{
					DrawMap.Drawtext(startX, startY + (i - prtstart), "                                           ", 0);
					DrawMap.Drawtext(startX, startY + (i - prtstart), group[i], 0);
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
	if (_kbhit())
	{
		if ('s' == _getch())return;
	}
	else
	{
		PrintStory(group, prtstart, prtend);
	}
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

	playerInfo.Playerclear();//������ �̸�, �������� �ʱ�ȭ
	while (1)//���丮 ��� �� �̸� �Է�
	{
		DrawMap.DrawBox(map_width, map_height);
		DrawMap.DrawTextBox(map_width, map_height);
		DrawMap.Drawtext(inboxTextx-6, inboxTexty, "�̸� : ", No);
		DrawMap.gotoxy(inboxTextx, inboxTexty);
		cin >> playername;
		if (playername.length() >= 10)
		{
			DrawMap.Drawtext(inboxTextx - 6, inboxTexty, "��������!(10������)", No);
			system("pause");
			continue;
		}
		playerInfo.Setname(playername);
		break;
	}

	system("cls");
	DrawMap.DrawBox(map_width, map_height);
	DrawMap.gotoxy(inboxTextx, inboxTexty);
	DrawMap.DrawTextBox(map_width, map_height);
	DrawMap.gotoxy(inboxTextx, inboxTexty);
	endtime = clock()/1000;
	while (life!=0)//������
	{
		
		starttime = clock()/1000;
		
		if (starttime - endtime > stagespeed)//�ð������� ������ ���� ���� & �ܾ� ������ ����
		{
			for (int i = 0; i < playerInfo.getLife(); i++)
			{
				DrawMap.Drawtext(5+i*2, map_height, "��", No);
			}
			DrawMap.Drawtext(map_width, map_height, "��������", No);
			DrawMap.Drawtext(map_width+8, map_height, to_string(stage), No);
			DrawMap.Drawtext(map_width*2-5, map_height, to_string(playerInfo.GetPoint()), No);
			if(wordmanager.setwordY(&playerInfo,&_curwordList) == false) break;//���� ���ӿ� ��µǴ� �ܾ� y��ǥ ��ȯ
			wordmanager.PrintWord(&_curwordList);//�ܾ����
			DrawMap.DrawTextBox(map_width, map_height);	
			DrawMap.Drawtext(inboxTextx, inboxTexty,checkword,No);
			wordmanager.SetNewWord(&_curwordList);//���ο�ܾ�����
		
			endtime = clock()/1000;
		
		}

		if (_kbhit())
		{
			if(wordmanager.DelWord((char)_getche(),&checkword) == true)
			{

				for (vector<WordInfo>::iterator iter = _curwordList.begin(); iter < _curwordList.end(); iter++)//�˻縦 ���� ���� �ܾ ���� ��� ����
				{
					if (iter->Checkword(checkword) == true)
					{
						int type = iter->GetWordSkill();
						DrawMap.Drawtext(iter->getWord_x(), iter->getWord_y(), "                ",No);
						_curwordList.erase(iter);
						switch (type)
						{
						case speedup : //�ܾ� �������� �ӵ�����
							stagespeed -= 0.3;
							break;
						case speeddown : // �ܾ� �������� �ӵ� ����
							stagespeed += 0.3;
							break;
						case doublepoint : // �����ι�ȹ��
							playerInfo.SetPoint(20);
							break;
						case screenclear : // ���� ��µǴ� �ܾ� ����
							for (vector<WordInfo>::iterator iter = _curwordList.begin(); iter < _curwordList.end(); iter++)
							{
								DrawMap.Drawtext(iter->getWord_x(), iter->getWord_y(), "                ", No);
							}
							_curwordList.clear();
							break;
						case gamestop : // �����ð� ���߱�
							break;
						default :
							playerInfo.SetPoint(10);
						}
						if (playerInfo.GetPoint() == stage * 150)
						{
							stage++;
							stagespeed = 1 / stage;
							playerInfo.SetPoint(-150);
						}
						
						break;
					}
				}
				DrawMap.Drawtext(inboxTextx, inboxTexty, "                ", No);
				DrawMap.gotoxy(inboxTextx + checkword.length(), inboxTexty);
				checkword.clear();
			}
			
		}
		
	}
	_curwordList.clear();
	playerInfo.Setstage(stage);
	DrawMap.Drawtext(map_width, map_height+1, "��������!", No);
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