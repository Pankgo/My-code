#include "GameManager.h"

GameManager* GameManager::GameM = NULL;

GameManager::GameManager()
{
	BackGround = BitMapManager::GetInstance()->GetImage(IMAGE_BACKGROUND); //백그라운드 이미지 생성
	startbutton = BitMapManager::GetInstance()->GetImage(IMAGE_STARTBUTTON);//시작버튼생성
	tryagain = BitMapManager::GetInstance()->GetImage(IMAGE_TRY);//시작버튼생성
	blacktile = BitMapManager::GetInstance()->GetImage(IMAGE_BLACKTILE); //백그라운드 이미지 생성
	whitetile = BitMapManager::GetInstance()->GetImage(IMAGE_WHITETILE);//시작버튼생성

	
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

	for (int x = 50, i = 0; i < 8; i++, x += 100)//타일 생성
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

page GameManager::PageCheck() {//페이지확인

	return (page)CurrStatue;
}
void GameManager::GameStart()//게임이 시작될경우 카드세팅
{
	if (CurrStatue == Start)
		CurrStatue = Game;

	
	
}

void GameManager::PageDraw(HDC hdc)//페이지 확인 후 그려내기
{
	BackGround->Draw(hdc, Back_X, Back_y,BACKGROUND);
	switch (CurrStatue)
	{
	case Start: StartP(hdc); break;
	case Game: GameP(hdc); break;
	default: EndP(hdc);	break;
	}		
}

void GameManager::StartP(HDC hdc)//시작화면 페이지
{
	startbutton->Draw(hdc, startb_x, startb_y,STARTBUTTON);
}
void GameManager::GameP(HDC hdc)//게임화면 페이지
{

}
void GameManager::EndP(HDC hdc) // 결과창 도출
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

bool GameManager::ColliderCheck(POINT point,HWND hwnd)//화면에서 이미지 눌렀는지확인
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
