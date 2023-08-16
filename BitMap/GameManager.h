#pragma once
#include<stdio.h>
#include<Windows.h>
#include <string>
#include <vector>
#include "BitMap.h"

#include"pieces.h"



#define WINDOWWIDTH 660
#define WINDOWHEIGHT 690



//윈도우 틀 등을 가지고 있어야된다


enum page//화면종류
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
	enum piecesTypex //x고정좌표
	{
		FROOKX = 0, //왼쪽 비숍 x좌표
		FHORSEX = 80, // 왼쪽 나이트 x좌표
		FBISHOPX = 160, // 왼쪽 비숍 x좌표
		KINGX= 240,
		QUEENX = 320,
		SBISHOPX = 400,//오른쪽 비숍 x좌표
		SHORSEX = 480,//오른쪽 비숍 x좌표
		SROOKX= 560,//오른쪽 비숍 x좌표


	};

	static GameManager* GameM;


	BitMap* startbutton; // 시작버튼이미지
	BitMap* BackGround; // 백그라운드이미지
	BitMap* tryagain; // 트라이어겐버튼
	BitMap* blacktile;
	BitMap* whitetile;

	RECT startRect;
	RECT BackGroundRect;
	RECT tryAgain;
	RECT blacktileRect;
	RECT whitetileRect;

	//std::vector<Tiles> tiles; // 게임판 타일의 정보 저장
	Tiles tiles[64] ;
	std::vector<_Chess*>pieces;//피스들의 정보 저장

	int startb_x, startb_y;//시작버튼위치
	int Back_X, Back_y;//백그라운드 위치
	int try_x, try_y;
	int CurrStatue;//페이지상태
	bool piecesmove = false;
	piecesColor gameturn = _WHITE; //현재 게임턴상태

public:
	static GameManager* GetInstance()
	{
		if (GameM == NULL)
			GameM = new GameManager;
		return GameM;
	}
	void GameStart();//시작화면인경우 게임시작으로 상태변경
	page PageCheck();//페이지 상태확인
	void PageDraw(HDC hdc);//현재 페이지 그리기
	GameManager();
	void GameP(HDC hdc);//게임페이지
	void StartP(HDC hdc);//시작페이지
	void EndP(HDC hdc);
	~GameManager();
	bool ColliderCheck(POINT point, HWND hWnd);
	void Init(HWND hWnd);
	void GoHome();
	void TilesSet();
	void PiecesSet();
};