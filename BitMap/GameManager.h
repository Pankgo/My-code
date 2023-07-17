#include<stdio.h>
#include<Windows.h>
#include"pieces.h"
#include"time.h"
#include <string>
#include <vector>
#include "BitMap.h"

//������ Ʋ ���� ������ �־�ߵȴ�


enum page//ȭ������
{
	Start,
	Game,
	End
};

enum tile
{
	black,
	white
};

class GameManager
{
	static GameManager* GameM;

	struct Tile //ī�弼�ÿ� �ʿ��� xy��ǥ ����ü
	{
		int x, y;
		tile tile;
	};


	BitMap* startbutton; // ���۹�ư�̹���
	BitMap* BackGround; // ��׶����̹���
	BitMap* tryagain; // Ʈ���̾�չ�ư
	BitMap* blacktile; // ������ Ÿ��
	BitMap* whitetile; // �Ͼ�� Ÿ��

	RECT startRect;
	RECT BackGroundRect;
	RECT tryAgain;
	RECT blacktileRect;
	RECT whitetileRect;

	std::vector<Tile> tiles; // ������ Ÿ���� ���� ����
	std::vector<Chess>pieces;//�ǽ����� ���� ����

	int startb_x, startb_y;//���۹�ư��ġ
	int Back_X, Back_y;//��׶��� ��ġ
	int try_x, try_y;
	int CurrStatue;//����������
	bool gamestop = false;

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
	bool GetGameStop() { return gamestop; }
};