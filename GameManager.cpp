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
void GameManager::PrintStory()//스토리 출력
{
	ifstream load;
	string group[26];
	string line;
	int start = 0, end = 0;
	int count = 0;
	int prtstart = 0, prtend = 0;
	int changey = 0;
	load.open("베네치아_스토리.txt");

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
	int saveitem = 0;//현재 단어가 출력되는 개수
	int randnum = 0;
	int sequence = 0;
	int level = 1;//게임 단계
	int starttime = 0, endtime = 0;

	while (!load.eof())//벡터에 출력할 단어 저장
	{
		getline(load, word);
		wordList[sequence] = word;
		sequence++;
	}
	
	while (1)//스토리 출력 및 이름 입력
	{
		DrawMap.DrawBox(map_width, map_height);
		DrawMap.DrawTextBox(map_width, map_height);
		DrawMap.DrawMidText(inboxTextx-6, inboxTexty, "이름 : ");
		cin >> playername;
		if (playername.length() >= 10)
		{
			DrawMap.DrawMidText(inboxTextx - 6, inboxTexty, "글자제한!(10자이하)");
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
				randnum = rand() % 76;// 76개의 숫자중 하나 랜덤으로 뽑기(중복있으면 다시)
				for (vector<WordInfo>::iterator iter = _curwordList.begin(); iter < _curwordList.end(); iter++)
				{
					if(iter->)
				}
			}
			
			int x = rand() % 59 + 1;//x좌표만 랜덤으로 설정하고  y좌표는 1에서 시작하기때문에 건들필요 x
			wordInfo.setWord(wordList[randnum],x);
		}
	}

}