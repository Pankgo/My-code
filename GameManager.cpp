#include "GameManager.h"

void GameManager::StartScreen()//초기화면 메뉴출력(게임시작, 랭크 출력, 종료)
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


void GameManager::Story()//스토리 출력
{
	ifstream load;
	string group[26];
	string line;
	int start = 0, end = 0;
	int count = 0;
	int prtstart = 20, prtend = 25;
	int changey = 0;
	int check = 6;
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
	int saveitem = 0;//현재 단어가 출력되는 개수
	int randnum = 0;
	int starttime = 0, endtime = 0;
	int stagespeed = 1;

	playerInfo.Playerclear();//점수와 이름, 스테이지 초기화
	while (1)//스토리 출력 및 이름 입력
	{
		DrawMap.DrawBox(map_width, map_height);
		DrawMap.DrawTextBox(map_width, map_height);
		DrawMap.Drawtext(inboxTextx-6, inboxTexty, "이름 : ", No);
		DrawMap.gotoxy(inboxTextx, inboxTexty);
		cin >> playername;
		if (playername.length() >= 10)
		{
			DrawMap.Drawtext(inboxTextx - 6, inboxTexty, "글자제한!(10자이하)", No);
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
	while (life!=0)//본게임
	{
		
		starttime = clock()/1000;
		
		if (starttime - endtime > stagespeed)//시간간격을 레벨에 따라 설정 & 단어 새로이 생성
		{
			for (int i = 0; i < playerInfo.getLife(); i++)
			{
				DrawMap.Drawtext(5+i*2, map_height, "♥", No);
			}
			DrawMap.Drawtext(map_width, map_height, "스테이지", No);
			DrawMap.Drawtext(map_width+8, map_height, to_string(stage), No);
			DrawMap.Drawtext(map_width*2-5, map_height, to_string(playerInfo.GetPoint()), No);
			if(wordmanager.setwordY(&playerInfo,&_curwordList) == false) break;//현재 게임에 출력되는 단어 y좌표 변환
			wordmanager.PrintWord(&_curwordList);//단어출력
			DrawMap.DrawTextBox(map_width, map_height);	
			DrawMap.Drawtext(inboxTextx, inboxTexty,checkword,No);
			wordmanager.SetNewWord(&_curwordList);//새로운단어저장
		
			endtime = clock()/1000;
		
		}

		if (_kbhit())
		{
			if(wordmanager.DelWord((char)_getche(),&checkword) == true)
			{

				for (vector<WordInfo>::iterator iter = _curwordList.begin(); iter < _curwordList.end(); iter++)//검사를 통해 같은 단어가 있을 경우 삭제
				{
					if (iter->Checkword(checkword) == true)
					{
						int type = iter->GetWordSkill();
						DrawMap.Drawtext(iter->getWord_x(), iter->getWord_y(), "                ",No);
						_curwordList.erase(iter);
						switch (type)
						{
						case speedup : //단어 떨어지는 속도증가
							stagespeed -= 0.3;
							break;
						case speeddown : // 단어 떨어지는 속도 감소
							stagespeed += 0.3;
							break;
						case doublepoint : // 점수두배획득
							playerInfo.SetPoint(20);
							break;
						case screenclear : // 현재 출력되는 단어 삭제
							for (vector<WordInfo>::iterator iter = _curwordList.begin(); iter < _curwordList.end(); iter++)
							{
								DrawMap.Drawtext(iter->getWord_x(), iter->getWord_y(), "                ", No);
							}
							_curwordList.clear();
							break;
						case gamestop : // 일정시간 멈추기
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
	DrawMap.Drawtext(map_width, map_height+1, "게임종료!", No);
	system("pause");
	rank.setPlayerRank(playerInfo);//플레이어 저장

}

 void GameManager:: PrintRank()
{
	 rank.SortRank();
	 system("cls");
	 DrawMap.DrawBox(map_width, map_height);
	 rank.PrintRank();
	 system("pause");
}