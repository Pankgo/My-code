#pragma once
#include<stdio.h>
#include<Windows.h>
#include <string>
#include <vector>
#include "BitMap.h"

#include"pieces.h"



#define WINDOWWIDTH 660
#define WINDOWHEIGHT 690



//������ Ʋ ���� ������ �־�ߵȴ�


enum page//ȭ������
{
	MAIN,
	Game,
	End
};

enum piecesType
{
	_king,
	_queen,
	_knight,
	_rook,
	_bishop,
	_pawn
};

enum piecesColor
{
	_BLACK,
	_WHITE
};



class GameManager
{
	enum piecesTypex //x������ǥ
	{
		FROOKX = 0, //���� ��� x��ǥ
		FHORSEX = 80, // ���� ����Ʈ x��ǥ
		FBISHOPX = 160, // ���� ��� x��ǥ
		KINGX= 240,
		QUEENX = 320,
		SBISHOPX = 400,//������ ��� x��ǥ
		SHORSEX = 480,//������ ��� x��ǥ
		SROOKX= 560,//������ ��� x��ǥ


	};

	static GameManager* GameM;


	BitMap* startbutton; // ���۹�ư�̹���
	BitMap* BackGround; // ��׶����̹���
	BitMap* tryagain; // Ʈ���̾�չ�ư
	BitMap* blacktile;
	BitMap* whitetile;

	RECT startRect;
	RECT BackGroundRect;
	RECT tryAgain;
	RECT blacktileRect;
	RECT whitetileRect;

	//std::vector<Tiles> tiles; // ������ Ÿ���� ���� ����
	Tiles tiles[64] ;
	std::vector<_Chess*>pieces;//�ǽ����� ���� ����

	int startb_x, startb_y;//���۹�ư��ġ
	int Back_X, Back_y;//��׶��� ��ġ
	int try_x, try_y;
	int CurrStatue;//����������
	bool piecesmove = false;
	piecesColor gameturn = _WHITE; //���� �����ϻ���

public:
	static GameManager* GetInstance()
	{
		if (GameM == NULL)
			GameM = new GameManager;
		return GameM;
	}
	void GameStart();//����ȭ���ΰ�� ���ӽ������� ���º���
	page PageCheck();//������ ����Ȯ��
	void PageDraw(HDC hdc);//���� ������ �׸���
	GameManager();
	void GameP(HDC hdc);//����������
	void StartP(HDC hdc);//����������
	void EndP(HDC hdc);
	~GameManager();
	bool ColliderCheck(POINT point, HWND hWnd);
	void Init(HWND hWnd);
	void GoHome();
	void TilesSet();
	void PiecesSet();
};