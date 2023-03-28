#pragma once
#include "Master.h"
#include "DrawMap.h"
#include "WordInfo.h"
#define MAXCOUNT 5

enum Menu {

	Start =1,
	Rank,
	End
};

class GameManager
{
	DrawMap DrawMap;//��ü���� ���ӹ�� �׸��� Ŭ����
	int map_width = 60, map_height = 30;//������ ��ü���� x,y
	int startX = map_width - 13;
	int startY = 10;
	int inboxTextx = map_width - 5, inboxTexty = map_height / 2 + 7;//�ڽ����� �ؽ�Ʈ �Է� ��ġ
	vector<WordInfo> _curwordList;//���� ���ӿ� ��µǴ� �ܾ��Ʈ
	string wordList[76];
	WordInfo wordInfo;
public:
	void StartScreen();
	void MainGame();
	void PrintRank();
	void StartMenu()
	{
		int startX = map_width - 13;
		int startY = 10;

		DrawMap.DrawMidText(startX,startY , "1.���� ����");
		DrawMap.DrawMidText(startX, startY+1, "2.��ũ ���");
		DrawMap.DrawMidText(startX, startY+2, "3.����");

	}
	void PrintStory();
};
	