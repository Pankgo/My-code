#include "GameManager.h"

GameManager* GameManager::GameM = NULL;

GameManager::GameManager()
{
	BackGround = BitMapManager::GetInstance()->GetImage(IMAGE_BACKGROUND); //��׶��� �̹��� ����
	startbutton = BitMapManager::GetInstance()->GetImage(IMAGE_STARTBUTTON);//���۹�ư����
	tryagain = BitMapManager::GetInstance()->GetImage(IMAGE_TRY);//���۹�ư����
	blacktile = BitMapManager::GetInstance()->GetImage(IMAGE_BLACKTILE); //��׶��� �̹��� ����
	whitetile = BitMapManager::GetInstance()->GetImage(IMAGE_WHITETILE);//���۹�ư����

	
	Back_X = 0, Back_y = 0;
	startb_x = 200,startb_y = 300;
	try_x = 200, try_y = 300;
	
	BackGroundRect.left = 500;
	BackGroundRect.top = 500;
	BackGroundRect.right = 700;
	BackGroundRect.bottom = 700;

	startRect.left = 0;
	startRect.top = 0;
	startRect.right = 300;
	startRect.bottom = 450;

	tryAgain.left = 0;
	tryAgain.top = 0;
	tryAgain.right = 300;
	tryAgain.bottom = 450;

	Tile newtile;
	tile starttile;

	for (int x = 50, i = 0; i < 8; i++, x += 100)//Ÿ�� ����
	{
		starttile;
		switch (i & 2)
		{
			case 1:
				starttile = white;
				break;
			default :
				starttile = black;
		}
		for (int y = 100, j = 0; j < 8; j++, y += 100)
		{
			newtile.x = x;
			newtile.y = y;
			newtile.tile = starttile;
			switch (starttile)
			{
			case white:
				starttile = black;
				break;
			default :
				starttile = white;
			}
			tiles.push_back(newtile);
		 
		}
	}

}

page GameManager::PageCheck() {//������Ȯ��

	return (page)CurrStatue;
}
void GameManager::GameStart()//������ ���۵ɰ�� ī�弼��
{
	if (CurrStatue == Start)
		CurrStatue = Game;

	
	
}

void GameManager::PageDraw(HDC hdc)//������ Ȯ�� �� �׷�����
{
	BackGround->Draw(hdc, Back_X, Back_y,BACKGROUND);
	switch (CurrStatue)
	{
	case Start: StartP(hdc); break;
	case Game: GameP(hdc); break;
	default: EndP(hdc);	break;
	}		
}

void GameManager::StartP(HDC hdc)//����ȭ�� ������
{
	startbutton->Draw(hdc, startb_x, startb_y,STARTBUTTON);
}
void GameManager::GameP(HDC hdc)//����ȭ�� ������
{

}
void GameManager::EndP(HDC hdc) // ���â ����
{
	tryagain->Draw(hdc, try_x, try_y, TRY);
	
}
GameManager::~GameManager()
{

}


void GameManager::GoHome() 
{ 
	if (CurrStatue == End)
		CurrStatue = Start;
}

bool GameManager::ColliderCheck(POINT point,HWND hwnd)//ȭ�鿡�� �̹��� ��������Ȯ��
{
	switch (gamestop)
	{
	case false:
		switch (CurrStatue)
		{
		case Start:
			if (PtInRect(&startRect, point))
			{
				GameManager::GetInstance()->GameStart();
				return true;
			}
			break;
		case End:
			if (PtInRect(&tryAgain, point))
			{
				GameManager::GetInstance()->GoHome();
				return true;
			}
			break;
		default:
			for (auto iter = pieces.begin(); iter < pieces.end(); iter++)
			{

			}
		}
		return true;
	default:
		return false;
	}
	 
}
void GameManager::Init(HWND hWnd)
{
	BitMapManager::GetInstance()->Init(hWnd);
}
