#include "GameManager.h"

GameManager* GameManager::GameM = NULL;

GameManager::GameManager()
{
	BackGround = BitMapManager::GetInstance()->GetImage(IMAGE_BACKGROUND); //백그라운드 이미지 생성
	startbutton = BitMapManager::GetInstance()->GetImage(IMAGE_STARTBUTTON);//시작버튼생성
	tryagain = BitMapManager::GetInstance()->GetImage(IMAGE_STARTBUTTON);//시작버튼생성
	
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

}

page GameManager::PageCheck() {//페이지확인
	if (CurrStatue == Start)
		return Start;
	return Game;
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

	while(set < NORMAL*2) // 카드 세팅
	{
		switch (imagecount)
		{
		case 0:
			image = IMAGE(rand() % 10);
			if (find(checkcards.begin(), checkcards.end(), image) != checkcards.end()) { continue; }//중복이미지가없을 경우 다시 뽑기
			checkcards.push_back(image);
			break;

		}
		while (1)//xy백터에서 위치뽑아내기
		{
			randxy = rand() % 16; //xy백터에서 가져올 인덱스 
			for (auto iter = cards.begin(); iter < cards.end(); iter++)//반복자를 통해 중복 세팅 확인
			{
				if (iter->GetX() == xy[randxy].x)
				{
					if (iter->GetY() == xy[randxy].y)
					{
						xycount = false;
						break;//통과못하면 다시
					}
				}
			}
			if (xycount == false)
			{
				xycount = true;
				continue;
			}
			break;
		}
		//이미지 인덱스
		card1.Init(image, xy[randxy].x, xy[randxy].y);
		
	
		cards.push_back(card1);//통과하면 세팅
		set++;
		switch (imagecount)
		{
		case 1:
			imagecount = 0;
			break;
		default:
			imagecount++;
		}
		
	}
}
void GameManager::PageDraw(HDC hdc)//페이지 확인 후 그려내기
{
	BackGround->Draw(hdc, Back_X, Back_y,BACKGROUND);
	if (CurrStatue == Start)
		StartP(hdc);
	else if (CurrStatue == Game)
		GameP(hdc);
	else
		EndP(hdc);
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
	bool result = false;
	int cardcount = 0;


	for (auto iter1 = cards.begin(); iter1 < cards.end() && result == false; iter1++)
	{
		if (iter1->ColliderCheck(point))//이미지 위에 있는지 확인
		{
			for (auto iter2 = cards.begin(); iter2 < cards.end() && result == false; iter2++)//만약 같은 카드가 2개 다 오픈되어있을경우 안뒤집어짐
			{
				if (iter2->CheckBitMap() == iter1->CheckBitMap())
				{
					if (iter2->GetCardState() == true && iter1->GetCardState() == true)
					{
						result = true;
					}
					else
					{
						iter1->ChangeState();
						result = true;
					}
					
				}
				

			}
		}
	
	}
	
	
}
bool GameManager::ColliderCheck(POINT point,page page)//화면에서 이미지 눌렀는지확인
{
	if (PtInRect(&startRect, point) && page == Start)
	{
		return true;
	}
	else if (PtInRect(&tryAgain, point) && page == End)
	{
		return true;
	}
	else
	{
		for (auto iter = cards.begin(); iter < cards.end(); iter++)
		{
			if (iter->ColliderCheck(point))return true;
		}
	}
	
	return false; 
}
void GameManager::Init(HWND hWnd)
{
	BitMapManager::GetInstance()->Init(hWnd);
	cards.clear();
}
