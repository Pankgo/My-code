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
void GameManager::PrintStory(string group[26],int prtstart,int prtend)
{

	if(prtend ==0)
	{
		return;
	}
	else
	{
		int end=0, start = 0;
		if (prtstart != 0)
		{
			prtstart--;
		}
		prtend--;
		PrintStory(group, prtstart, prtend);
		end = clock() / 1000;
		while (1)
		{
			start = clock() / 1000;
			if (start - end > 1)
			{
				for (int i = prtstart; i < prtend; i++)
				{
					DrawMap.Drawtext(startX, startY + (i - prtstart), "                                           ");
					DrawMap.Drawtext(startX, startY + (i - prtstart), group[i]);
				}
				break;
			}
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
	/*while(26 - 6 > prtstart)
	{
			start = clock() / 1000;
			if (start - end > 1)
			{
					end = clock() / 1000;

					for (int i = prtstart; i < prtend; i++)
					{
						DrawMap.Drawtext(startX, startY + (i - prtstart), "                                           ");
						DrawMap.Drawtext(startX, startY + (i - prtstart), group[i]);
					}

					if (6 > prtend) prtend++;
					else prtstart++;
				}

				if (_kbhit())
				{
					if('s' ==_getch()) break;
				}
			}*/
}

void GameManager::MainGame()
{
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
	int sequence = 0;
	int starttime = 0, endtime = 0;
	int stagespeed = 1;

	while (!load.eof())//���Ϳ� ����� �ܾ� ����
	{
		getline(load, word);
		wordList[sequence] = word;
		sequence++;
	}
	Story();
	playerInfo.Playerclear();//������ �̸�, �������� �ʱ�ȭ
	while (1)//���丮 ��� �� �̸� �Է�
	{
		DrawMap.DrawBox(map_width, map_height);
		DrawMap.DrawTextBox(map_width, map_height);
		DrawMap.Drawtext(inboxTextx-6, inboxTexty, "�̸� : ");
		DrawMap.gotoxy(inboxTextx, inboxTexty);
		cin >> playername;
		if (playername.length() >= 10)
		{
			DrawMap.Drawtext(inboxTextx - 6, inboxTexty, "��������!(10������)");
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
	endtime = clock()/1000;

	while (life!=0)//������
	{
		
		starttime = clock()/1000;
		
		if (starttime - endtime > 0.1)//�ð������� ������ ���� ���� & �ܾ� ������ ����
		{
			for (int i = 0; i < life; i++)
			{
				DrawMap.Drawtext(5+i*2, map_height, "��");
			}
			DrawMap.Drawtext(map_width, map_height, "��������");
			DrawMap.Drawtext(map_width+8, map_height, to_string(stage));
			DrawMap.Drawtext(map_width*2-5, map_height, to_string(playerInfo.GetPoint()));
			for (vector<WordInfo>::iterator iter = _curwordList.begin(); iter < _curwordList.end(); iter++)//���ӿ� ��µǴ� �ܾ�� y��ǥ ��ȭ
			{
				DrawMap.Drawtext(iter->getWord_x(), iter->getWord_y(), "                ");
				iter->setWord_y();
				if (iter->getWord_y() >= map_height-1 )//�ش�ܾ �ʹ����� ����� �Ǹ� ���Ϳ��� ������ ���ÿ� ������ 1����
				{
					_curwordList.erase(iter);
					life--;
					DrawMap.Drawtext(5 + life*2, map_height, "  ");
					break;
				}
			}
			for (vector<WordInfo>::iterator iter = _curwordList.begin(); iter < _curwordList.end(); iter++)//���� ����ִ� ���� ���
			{
				DrawMap.Drawtext(iter->getWord_x(), iter->getWord_y(), iter->getWord());
			}
			DrawMap.DrawTextBox(map_width, map_height);
			DrawMap.gotoxy(inboxTextx, inboxTexty);
			while (1)
			{
				randnum = rand() % 75;// 75���� ������ �ϳ� �������� �̱�(�ߺ������� �ٽ�)
				for (vector<WordInfo>::iterator iter = _curwordList.begin(); iter < _curwordList.end(); iter++)//�˻縦 ���� ���� �ܾ ���� ��� while�� ��Ƽ��
				{
					if (iter->Checkword(wordList[randnum]) == true)
					{
						continue;
					}
				}
				break;
			}
			int x = rand() % 100 +1;//x��ǥ�� �������� �����ϰ�  y��ǥ�� 1���� �����ϱ⶧���� �ǵ��ʿ� x
			wordInfo.setWord(wordList[randnum],x);
			_curwordList.push_back(wordInfo);
			endtime = clock()/1000;
		
		}

		if (_kbhit())
		{
			word.clear();
			gets_s(answer, sizeof(answer));
			for (int i = 0; answer[i] != NULL; i++)
			{
				word += answer[i];
			}
			for (vector<WordInfo>::iterator iter = _curwordList.begin(); iter < _curwordList.end(); iter++)//�˻縦 ���� ���� �ܾ ���� ��� ����
			{
				if (iter->Checkword(word) == true)
				{
					DrawMap.Drawtext(iter->getWord_x(), iter->getWord_y(), "                ");
					_curwordList.erase(iter);
					playerInfo.SetPoint(10);
					if (playerInfo.GetPoint() == stage * 150)
					{
						stage++;
						stagespeed = 1 / stage;

					}
					break;
				}
			}
		}
		
	}
	DrawMap.Drawtext(map_width, map_height+1, "��������!");
	system("pause");
	_PlayerRank.push_back(playerInfo);

}

 void GameManager:: PrintRank()
{
	 int y = 0;
	 for (vector<PlayerInfo>::iterator iter = _PlayerRank.begin(); iter < _PlayerRank.end(); iter++)//�˻縦 ���� ���� �ܾ ���� ��� ����
	 {
		 DrawMap.Drawtext(map_width, 5 + y,iter->getName());
		 y++;
	 }
	 system("pause");
}