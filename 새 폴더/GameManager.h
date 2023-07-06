#include<stdio.h>
#include<Windows.h>
#include"Card.h"
#include"time.h"

#define CARDMAX 12
#define NORMAL 8 // ���� ���̵� ����
#define WINDOWHEIGHT 640
#define WINDOWWIDTH 490

	enum page//ȭ������
	{
		Start,
		Game,
		End
	};

	class GameManager
	{
		static GameManager* GameM;
		struct Getxy //ī�弼�ÿ� �ʿ��� xy��ǥ ����ü
		{
			int x, y;
		};


		BitMap* startbutton; // ���۹�ư�̹���
		BitMap* BackGround; // ��׶����̹���
		BitMap* tryagain; // Ʈ���̾�չ�ư

		RECT startRect;
		RECT BackGroundRect;
		RECT tryAgain;

		int startb_x, startb_y;//���۹�ư��ġ
		int Back_X, Back_y;//��׶��� ��ġ
		int try_x, try_y;
		int cardcount = 0; //ī��� ���µǾ��ִ��� Ȯ��
		int CurrStatue;//����������
		bool gamestop = false;

		std::vector<Card> cards;// [NORMAL] ;
		std::vector<IMAGE>checkcards;//�̹��� �ߺ�Ȯ��
		std::vector<Getxy>xy;//2���� ���͸� �̿��� xy��ǥ �������
		std::vector<Card>opencards;

		Card* select1 = nullptr, * select2 = nullptr;

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
		bool ColliderCheck(POINT point,page page);
		void Init(HWND hWnd);
		void CardCheck(POINT point);
		void GameStop();
		bool GetGameStop() { return gamestop; }
	};

