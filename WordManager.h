#pragma once
#include"GameManager.h"


class WordManager
{
	DrawMap DrawMap;
	WordInfo wordInfo;
	int map_width = 60, map_height = 30;
	string wordList[76];//단어 저장
	int sequence = 0;
	string word;
	ifstream load;


public :
	WordManager()
	{
		load.open("Word.txt");
		while (!load.eof())//벡터에 출력할 단어 저장
		{
			getline(load, word);
			wordList[sequence] = word;
			sequence++;
		}
	};
	string getWord(int _str)
	{
		return wordList[_str];
	}
	void setwordY(PlayerInfo *player,vector<WordInfo>*_curwordList)//y좌표 변환
	{
		for (vector<WordInfo>::iterator iter = _curwordList->begin(); iter < _curwordList->end(); iter++)//게임에 출력되는 단어들 y좌표 변화
		{
			DrawMap.Drawtext(iter->getWord_x(), iter->getWord_y(), "                ");
			iter->setWord_y();
			if (iter->getWord_y() >=  map_height-1)//해당단어가 맵밖으로 벗어나게 되면 벡터에서 삭제와 동시에 라이프 1깍임
			{
				_curwordList->erase(iter);
				player->SetLife(-1);
				DrawMap.Drawtext(5 + player->getLife() * 2, map_height, "  ");
				break;
			}
		}
	}

	void PrintWord(vector<WordInfo>* _curwordList)
	{
		for (vector<WordInfo>::iterator iter = _curwordList->begin(); iter < _curwordList->end(); iter++)//현재 들어있는 문장 출력
		{
			DrawMap.Drawtext(iter->getWord_x(), iter->getWord_y(), iter->getWord());
		}
	}

	void SetNewWord(vector<WordInfo>* _curwordList)//새로운단어저장
	{
		srand(time(NULL));
		int randnum = 0;
		while (1)
		{
			randnum = rand() % 75;// 75개의 숫자중 하나 랜덤으로 뽑기(중복있으면 다시)
			for (vector<WordInfo>::iterator iter = _curwordList->begin(); iter < _curwordList->end(); iter++)//검사를 통해 같은 단어가 있을 경우 while문 컨티뉴
			{
				if (iter->Checkword(wordList[randnum]) == true)
				{
					continue;
				}
			}
			break;
		}
		int x = rand() % 100 + 1;//x좌표만 랜덤으로 설정하고  y좌표는 1에서 시작하기때문에 건들필요 x
		wordInfo.setWord(wordList[randnum], x);
		_curwordList->push_back(wordInfo);
	}


};