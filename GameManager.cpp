#include "GameManager.h"

void GameManager::StartScreen()//�ʱ�ȭ�� �޴����(���ӽ���, ��ũ ���, ����)
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
void GameManager::PrintStory()//���丮 ���
{
	ifstream load;
	string group[26];
	string line;
	int start = 0, end = 0;
	int count = 0;
	int prtstart = 0, prtend = 0;
	int changey = 0;
	load.open("����ġ��_���丮.txt");

	while (!load.eof())
	{
		getline(load, line);
		group[start] = line;
		start++;
	}

	end = clock() / 1000;
	while (1)
	{
		start = clock() / 1000;
		if (start - end > 2)
		{
			system("cls");
			for (int i = prtstart; i <= prtend; i++)
			{
				DrawMap.DrawMidText(startX, startY+changey,group[i]);
				changey++;
			}
			prtend++;
			changey = 0;
			if (count == MAXCOUNT)
			{
				prtstart++;
			}
			else
			{
				count++;
			}
			start = 0;
			end = clock() / 1000;

		}
	}
}

void GameManager::MainGame()
{
	string playername = "";
	int Life = 7;
	int select;
	string word;
	ifstream load;
	load.open("Word.txt");
	int saveitem = 0;//���� �ܾ ��µǴ� ����
	int randnum = 0;
	int sequence = 0;
	int level = 1;//���� �ܰ�
	int starttime = 0, endtime = 0;

	while (!load.eof())//���Ϳ� ����� �ܾ� ����
	{
		getline(load, word);
		wordList[sequence] = word;
		sequence++;
	}
	
	while (1)//���丮 ��� �� �̸� �Է�
	{
		DrawMap.DrawBox(map_width, map_height);
		DrawMap.DrawTextBox(map_width, map_height);
		DrawMap.DrawMidText(inboxTextx-6, inboxTexty, "�̸� : ");
		cin >> playername;
		if (playername.length() >= 10)
		{
			DrawMap.DrawMidText(inboxTextx - 6, inboxTexty, "��������!(10������)");
			system("pause");
			continue;
		}
		break;
	}
	DrawMap.DrawTextBox(map_width, map_height);
	
	endtime = clock() / 1000;
	while (1)
	{
		starttime = clock() / 1000;
		if (starttime - endtime > 3)
		{
			while (1)
			{
				randnum = rand() % 76;// 76���� ������ �ϳ� �������� �̱�(�ߺ������� �ٽ�)
				for (vector<WordInfo>::iterator iter = _curwordList.begin(); iter < _curwordList.end(); iter++)
				{
					if(iter->)
				}
			}
			
			int x = rand() % 59 + 1;//x��ǥ�� �������� �����ϰ�  y��ǥ�� 1���� �����ϱ⶧���� �ǵ��ʿ� x
			wordInfo.setWord(wordList[randnum],x);
		}
	}

}