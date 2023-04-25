#pragma once
#include "Master.h"
#include "DrawMap.h"
#include "PlayerInfo.h"
#include "WordInfo.h"
#include "WordManager.h"
#include "Rank.h"
#define MAXCOUNT 5

enum Menu {

	Start =1,
	Rank,
	End
};

class GameManager
{
	DrawMap DrawMap;//��ü���� ���ӹ�� �׸��� Ŭ����
	vector<WordInfo> _curwordList;//���� ���ӿ� ��µǴ� �ܾ��Ʈ
	int map_width = 60, map_height = 30;//������ ��ü���� x,y
	int startX = map_width - 13;
	int startY = 10;
	int inboxTextx = map_width - 5, inboxTexty = map_height / 2 + 7;//�ڽ����� �ؽ�Ʈ �Է� ��ġ
	PlayerInfo playerInfo;
	vector<PlayerInfo> _PlayerRank;
	WordManager wordmanager;
	vector<PlayerInfo> _CheckRank;
	_Rank rank;

public:
	void StartScreen();
	void MainGame();
	void PrintRank();
	int GetMapWidth()
	{
		return map_width;
	}
	void StartMenu()
	{
		int startX = map_width - 13;
		int startY = 10;

		DrawMap.Drawtext(startX,startY , "1.���� ����");
		DrawMap.Drawtext(startX, startY+1, "2.��ũ ���");
		DrawMap.Drawtext(startX, startY+2, "3.����");

	}
	int GetmapY()
	{
		return map_height;
	}
	int GetmapX()
	{
		return map_width;
	}
	void Story();
	bool PrintStory(string group[26],int prtstart,int ptrend);
	~GameManager()
	{
		ofstream recordRank;
		recordRank.open("RankTxT.txt");
		vector<PlayerInfo> ::iterator iter = rank.GetRank().begin();
		
		while(!recordRank.is_open())
		{
			recordRank << iter->getName();
			recordRank << iter->GetPoint();
			recordRank << iter->Getstage();
			iter++;
		}
	}
};
	