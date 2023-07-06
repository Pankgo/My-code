#include<stdio.h>
#include<Windows.h>
#include"Card.h"
#include"time.h"

#define CARDMAX 12
#define NORMAL 8 // 게임 난이도 설정
#define WINDOWHEIGHT 640
#define WINDOWWIDTH 490

	enum page//화면종류
	{
		Start,
		Game,
		End
	};

	class GameManager
	{
		static GameManager* GameM;
		struct Getxy //카드세팅에 필요한 xy좌표 구조체
		{
			int x, y;
		};


		BitMap* startbutton; // 시작버튼이미지
		BitMap* BackGround; // 백그라운드이미지
		BitMap* tryagain; // 트라이어겐버튼

		RECT startRect;
		RECT BackGroundRect;
		RECT tryAgain;

		int startb_x, startb_y;//시작버튼위치
		int Back_X, Back_y;//백그라운드 위치
		int try_x, try_y;
		int cardcount = 0; //카드다 오픈되어있는지 확인
		int CurrStatue;//페이지상태
		bool gamestop = false;

		std::vector<Card> cards;// [NORMAL] ;
		std::vector<IMAGE>checkcards;//이미지 중복확인
		std::vector<Getxy>xy;//2차원 백터를 이용한 xy좌표 저장백터
		std::vector<Card>opencards;

		Card* select1 = nullptr, * select2 = nullptr;

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
		bool ColliderCheck(POINT point,page page);
		void Init(HWND hWnd);
		void CardCheck(POINT point);
		void GameStop();
		bool GetGameStop() { return gamestop; }
	};

