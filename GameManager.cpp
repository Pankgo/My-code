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
	system("cls");		
	DrawMap.DrawBox(map_width, map_height);
	DrawMap.DrawTextBox(map_width, map_height);

			while(26 - 6 > prtstart)
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
			}
}

void GameManager::MainGame()
{
	srand(time(NULL));
	string playername = "";
	int life = 7;
	int select;
	string word;
	ifstream load;
	load.open("Word.txt");
	int saveitem = 0;//현재 단어가 출력되는 개수
	int randnum = 0;
	int sequence = 0;
	int starttime = 0, endtime = 0;

	while (!load.eof())//벡터에 출력할 단어 저장
	{
		getline(load, word);
		wordList[sequence] = word;
		sequence++;
	}
	PrintStory();
	while (1)//스토리 출력 및 이름 입력
	{
		DrawMap.DrawBox(map_width, map_height);
		DrawMap.DrawTextBox(map_width, map_height);
		DrawMap.Drawtext(inboxTextx-6, inboxTexty, "이름 : ");
		DrawMap.gotoxy(inboxTextx, inboxTexty);
		cin >> playername;
		if (playername.length() >= 10)
		{
			DrawMap.Drawtext(inboxTextx - 6, inboxTexty, "글자제한!(10자이하)");
			system("pause");
			continue;
		}
		break;
	}

	system("cls");
	DrawMap.DrawBox(map_width, map_height);
	DrawMap.DrawTextBox(map_width, map_height);
	endtime = clock();
	while (life!=0)//본게임
	{
		
		starttime = clock();
		
		DrawMap.DrawTextBox(map_width, map_height);
		if (starttime - endtime > 1000)//시간간격을 레벨에 따라 설정 & 단어 새로히 생성
		{
			endtime = clock();
			for (vector<WordInfo>::iterator iter = _curwordList.begin(); iter < _curwordList.end(); iter++)//현재 들어있는 문장 출력
			{
				DrawMap.Drawtext(iter->getWord_x(), iter->getWord_y(), iter->getWord());
			}
			while (1)
			{
				randnum = rand() % 76;// 76개의 숫자중 하나 랜덤으로 뽑기(중복있으면 다시)
				for (vector<WordInfo>::iterator iter = _curwordList.begin(); iter < _curwordList.end(); iter++)//검사를 통해 같은 단어가 있을 경우 while문 컨티뉴
				{
					if (iter->Checkword(wordList[randnum]) == true)
					{
						continue;

					}
				}
				break;
			}
			int x = rand() % 57 + 2;//x좌표만 랜덤으로 설정하고  y좌표는 1에서 시작하기때문에 건들필요 x
			wordInfo.setWord(wordList[randnum],x);
			_curwordList.push_back(wordInfo);
		}
		for (vector<WordInfo>::iterator iter = _curwordList.begin(); iter < _curwordList.end(); iter++)//게임에 출력되는 단어들 y좌표 변화
		{
			DrawMap.Drawtext(iter->getWord_x(), iter->getWord_y(),"                " );
			iter->setWord_y();
			if (iter->getWord_y() >= map_height-1)//해당단어가 맵밖으로 벗어나게 되면 벡터에서 삭제와 동시에 라이프 1깍임
			{
				_curwordList.erase(iter);
				life--;
			}
		}
		//if (_kbhit())
		//{
		//	word+=_getch();
		//	for (vector<WordInfo>::iterator iter = _curwordList.begin(); iter < _curwordList.end(); iter++)//입력을 받았을 경우 맞을 경우 삭제
		//	{
		//		if (word == iter->getWord())
		//		{
		//			_curwordList.erase(iter);
		//		}
		//	}
		//}
	}

}