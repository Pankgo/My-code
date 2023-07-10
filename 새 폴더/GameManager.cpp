#include "GameManager.h"

GameManager* GameManager::GameM = NULL;

GameManager::GameManager()
{
	BackGround = BitMapManager::GetInstance()->GetImage(IMAGE_BACKGROUND); //백그라운드 이미지 생성
	startbutton = BitMapManager::GetInstance()->GetImage(IMAGE_STARTBUTTON);//시작버튼생성
	tryagain = BitMapManager::GetInstance()->GetImage(IMAGE_TRY);//시작버튼생성
	
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

	Getxy getxy;//구조체 선언
	
	for (int x = 50, i = 0; i < 4; i++, x += 100)//카드게임안의 카드들 xy좌표 백터에 저장
	{
		for (int y = 100, j = 0; j < 4; j++, y += 100)
		{
			getxy.x = x;
			getxy.y = y;
			xy.push_back(getxy);
		}
	}

	//enum
	//{
	//	StartX = 50, StartY = 100,
	//	W = 100, H = 100,
	//	PaddingX = 10, PaddingY = 10
	//};
	//for (int x = 0; x < 4; x++)
	//{
	//	for (int y = 0; y < 4; y++)
	//	{
	//		getxy.x = StartX + x * (W + PaddingX);
	//		getxy.y = StartY + y * (H + PaddingY);
	//	}
	//}
}

page GameManager::PageCheck() {//페이지확인
	/*switch (CurrStatue)
	{
	case Start:
		return Start;
	case End:
		return End;
	default:
		return Game;
	}*/
	return (page)CurrStatue;
}
void GameManager::GameStart()//게임이 시작될경우 카드세팅
{
	if (CurrStatue == Start)
		CurrStatue = Game;

	Card card1;
	int set = 0;
	int randxy;//xy좌표 인덱스 저장변수
	int imagecount = 0;//같은 이미지가 2개 들어갔는지 검사
	IMAGE image;
	bool xycount = true;

	std::vector<IMAGE> images;

	int removeImage[2]; 
	int randnum;
	removeImage[0] = rand() % IMAGE_COUNT;
	
	while (1) // 이미지10장중 랜덤으로 2장빼기
	{
		randnum = rand() % IMAGE_COUNT;
		if (removeImage[0] == randnum)
		{
			continue;
		}
		else
		{
			removeImage[1] = randnum;
			break;
		}
	}

	for (int i = IMAGE_START; IMAGE_COUNT > i; i++) // 이미지 생성
	{
		if (i == removeImage[0] || i == removeImage[1]) continue;

		images.push_back((IMAGE)i);
		images.push_back((IMAGE)i);
	}

	for (int i = 0; images.size(); i++)
	{
		int image_index = rand() % images.size();
		image = images[image_index];
		images.erase(images.begin() + image_index);

		card1.Init(image, xy[i].x, xy[i].y);
		cards.push_back(card1);
	}

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

	for (auto iter = cards.begin(); iter < cards.end(); iter++)//반복자를 통해 중복 세팅 확인
	{
		iter->Draw(hdc, CARDIMAGE);
	}
}
void GameManager::EndP(HDC hdc) // 결과창 도출
{
	tryagain->Draw(hdc, try_x, try_y, TRY);
	
}
GameManager::~GameManager()
{

}

void GameManager::CardCheck(POINT point)//카드체크
{
	

	for (int i = 0 ; cards.size() > i; i++)
	{
		if (cards[i].ColliderCheck(point))
		{
			if (nullptr == select1) { select1 = &cards[i]; select1->ChangeState(true);  }
			else
			{
				select2 = &cards[i];
				select2->ChangeState(true);
				if (select1->CheckBitMap() == select2->CheckBitMap()) // 같은 이미지인지 확인
				{

					select1 = nullptr;
					select2 = nullptr;
					
				}
				else
				{
					gamestop = true;
				}
			}
			break;
		}
	}

	int opencount = 0; // 카드가 다 앞으로 되어있는지 확인
	for (int i = 0; cards.size() > i; i++)
	{
		if (cards[i].GetCardState() == true)
		{
			opencount++;
		}
	}
	if (opencount == NORMAL*2)
	{
		CurrStatue = End;
	}




	
}
void GameManager::GoHome() 
{ 
	if (CurrStatue == End)
		CurrStatue = Start;
}
void GameManager::GameStop(HWND hwnd)
{

	select1->ChangeState(false);
	select2->ChangeState(false);
	// 선택된 두 카드 뒷면으로 돌리기
	select1 = nullptr;
	select2 = nullptr;
	KillTimer(hwnd, 1);
	gamestop = false;
}
bool GameManager::ColliderCheck(POINT point,HWND hwnd)//화면에서 이미지 눌렀는지확인
{
	//page _page = GameManager::GetInstance()->PageCheck();
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

			for (auto iter = cards.begin(); iter < cards.end(); iter++)
			{
				if (iter->ColliderCheck(point))
				{
					GameManager::GetInstance()->CardCheck(point);
					if (gamestop)
					{
						SetTimer(hwnd, 1, 2000, NULL);
					}
					return true;
				}
			}
			break;
		}
		/*
		if (PtInRect(&startRect, point) && _page == Start)
		{
			GameManager::GetInstance()->GameStart();
			return true;
		}
		else if (PtInRect(&tryAgain, point) && _page == End)
		{
			GameManager::GetInstance()->GoHome();
			return true;
		}
		else
		{
			for (auto iter = cards.begin(); iter < cards.end(); iter++)
			{
				if (iter->ColliderCheck(point) == true)
				{
					GameManager::GetInstance()->CardCheck(point);
					if (gamestop == true)
					{
						SetTimer(hwnd, 1, 2000, NULL);
					}
					return true;
				}
			}
		}*/
		return true;
	default:
		return false;
	}
	 
}
void GameManager::Init(HWND hWnd)
{
	BitMapManager::GetInstance()->Init(hWnd);
	cards.clear();
}
