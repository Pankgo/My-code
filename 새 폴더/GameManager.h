#include<stdio.h>
#include<Windows.h>
#include"Card.h"
#define CARDMAX 12
#define NORMAL 8 // ���� ���̵� ����


class GameManager
{
	static GameManager* GameM;

	enum page//ȭ������
	{
		Start,
		Game,
	};

	BitMap* startbutton; // ���۹�ư�̹���
	BitMap* BackGround; // ��׶����̹���

	RECT startRect;
	RECT BackGroundRect;

	int startb_x, startb_y;//���۹�ư��ġ
	int Back_X, Back_y;//��׶��� ��ġ

	int CurrStatue;//����������

	Card* cards;// [NORMAL] ;
	
public:
	static GameManager* GetInstance()
	{
		if (GameM == NULL)
			GameM = new GameManager;
		return GameM;
	}
	bool GameStartCheck(POINT point);//���ӽ��� �������� Ȯ��
	bool PageCheck();//������ ����Ȯ��
	void PageDraw(HDC hdc);//���� ������ �׸���
	GameManager();
	void GameP(HDC hdc);//����������
	void StartP(HDC hdc);//����������
	~GameManager();

	void Init(HWND hWnd);
};

