#include<stdio.h>
#include<Windows.h>
#include"Card.h"
#define CARDMAX 12
#define NORMAL 8 // 게임 난이도 설정


class GameManager
{
	static GameManager* GameM;

	enum page//화면종류
	{
		Start,
		Game,
	};

	BitMap* startbutton; // 시작버튼이미지
	BitMap* BackGround; // 백그라운드이미지

	RECT startRect;
	RECT BackGroundRect;

	int startb_x, startb_y;//시작버튼위치
	int Back_X, Back_y;//백그라운드 위치

	int CurrStatue;//페이지상태

	Card* cards;// [NORMAL] ;
	
public:
	static GameManager* GetInstance()
	{
		if (GameM == NULL)
			GameM = new GameManager;
		return GameM;
	}
	bool GameStartCheck(POINT point);//게임시작 눌렀는지 확인
	bool PageCheck();//페이지 상태확인
	void PageDraw(HDC hdc);//현재 페이지 그리기
	GameManager();
	void GameP(HDC hdc);//게임페이지
	void StartP(HDC hdc);//시작페이지
	~GameManager();

	void Init(HWND hWnd);
};

