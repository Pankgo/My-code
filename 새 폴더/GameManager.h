#include<stdio.h>
#include<Windows.h>
#include"Card.h"
#define CARDMAX 12
#define NORMAL 8 // ���� ���̵� ����
	enum page//ȭ������
	{
		Start,
		Game,
	};

class GameManager
{
	static GameManager* GameM;



	BitMap* startbutton; // ���۹�ư�̹���
	BitMap* BackGround; // ��׶����̹���

	RECT startRect;
	RECT BackGroundRect;

	int startb_x, startb_y;//���۹�ư��ġ
	int Back_X, Back_y;//��׶��� ��ġ

	int CurrStatue;//����������

	std::vector<Card> cards;// [NORMAL] ;
	
public:
	static GameManager* GetInstance()
	{
		if (GameM == NULL)
			GameM = new GameManager;
		return GameM;
	}
	bool GameStartCheck(POINT point);//���ӽ��� �������� Ȯ��
	page PageCheck();//������ ����Ȯ��
	void PageDraw(HDC hdc);//���� ������ �׸���
	GameManager();
	void GameP(HDC hdc);//����������
	void StartP(HDC hdc);//����������
	~GameManager();
	bool ColliderCheck(POINT point);
	void Init(HWND hWnd);
	bool CardCheck(POINT point);
};

