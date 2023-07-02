#include<stdio.h>
#include<Windows.h>
#include"Card.h"
#define CARDMAX 12


class GameManager
{
	enum page//화면종류
	{
		Start,
		Game,
	};
	BitMap* startbutton;
	RECT startRect;
	int startb_x;
	int startb_y;
	int CurrStatue;//페이지상태
	//Card Image[CARDMAX];
	
public:
	bool GameStartCheck(POINT point);//게임시작 눌렀는지 확인
	bool PageCheck();//페이지 상태확인
	void PageDraw(HDC hdc);//현재 페이지 그리기
	GameManager();
	void GameP(HDC hdc);//게임페이지
	void StartP(HDC hdc);//시작페이지
	~GameManager();
};

