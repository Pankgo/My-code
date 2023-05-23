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
	enum skill
	{
		No,
		speedup,
		speeddown,
		doublepoint,
		screenclear,
		gamestop,
	};
	DrawMap DrawMap;//��ü���� ���ӹ�� �׸��� Ŭ����
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
	GameManager()
	{
		rank.LoadRank();
	}
	~GameManager()
	{
		rank.SaveRank();
	}
	void StartMenu()
	{

		DrawMap.Drawtext(startX,startY , "1.���� ����", 0);
		DrawMap.Drawtext(startX, startY+1, "2.��ũ ���", 0);
		DrawMap.Drawtext(startX, startY+2, "3.����", 0);

	}
	int GetmapH()
	{
		return map_height;
	}
	void Story();
	bool PrintStory(string group[26],int prtstart,int ptrend);
};
	