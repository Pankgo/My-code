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

	TilesSet();
	PiecesSet();

}
void GameManager::TilesSet() // 타일세팅
{
	tile starttile;
	Tiles newtile;
	int start = 0;

	for (int x = 0, i = 0; i < 8; i++, x += 80)//타일 생성
	{
		switch (i % 2)
		{
		case 1:
			starttile = white;
			break;
		default:
			starttile = black;
		}
		for (int y = 0, j = 0; j < 8; j++, y += 80)
		{

			switch (starttile)
			{
			case white:
				newtile.Init(IMAGE_WHITETILE, x, y);
				starttile = black;
				break;
			default:
				newtile.Init(IMAGE_BLACKTILE, x, y);
				starttile = white;
			}
			tiles[start++]= newtile;

		}
	}
}

void GameManager::PiecesSet() // 피스세팅
{
	King king;
	Queen queen;
	Horse horse;
	Rook rook;
	BiShop bishop;
	Pawn pawn;

	int x = 0, y = 80; // 화이트 폰 초기 위치
	IMAGE startcolor = IMAGE_WhitePawn;
	for (int pawn_count = 0; pawn_count < 16; pawn_count++) // 폰 이미지 및 위치 세팅
	{
		if (pawn_count == 8)
		{
			x = 0; y = 480; //블랙 폰 초기위치
			startcolor = IMAGE_BlackPawn;
		}
		pawn.SetXY(x, y, startcolor);
		pieces.push_back(new Pawn(pawn));
		x += 80;
	}
	x = 0; y = 0;
	for (int pieces_count = 0; pieces_count < 5; pieces_count++) // 나머지 기물들 이미지 및 위치 세팅
	{
		switch ((piecesType)pieces_count)
		{
		case _king: 
			king.SetXY(KINGX, y, IMAGE_WhiteKing);
			pieces.push_back(new King(king));
			king.SetXY(KINGX, y+80*7, IMAGE_BlackKing);
			pieces.push_back(new King(king));
			break;
		case _queen: 
			queen.SetXY(QUEENX, y, IMAGE_WhiteQueen);
			pieces.push_back(new Queen(queen));
			queen.SetXY(QUEENX, y + 80 * 7, IMAGE_BlackQueen);
			pieces.push_back(new Queen(queen));
			break;
		case _knight: 
			horse.SetXY(FHORSEX, y, IMAGE_WhiteHorse);
			pieces.push_back(new Horse(horse));
			horse.SetXY(SHORSEX, y, IMAGE_WhiteHorse);
			pieces.push_back(new Horse(horse));
			horse.SetXY(FHORSEX, y + 80 * 7, IMAGE_BlackHorse);
			pieces.push_back(new Horse(horse));
			horse.SetXY(SHORSEX, y + 80 * 7, IMAGE_BlackHorse);
			pieces.push_back(new Horse(horse));
			break; 
		case _rook: 
			rook.SetXY(FROOKX, y, IMAGE_WhiteRook);
			pieces.push_back(new Rook(rook));
			rook.SetXY(SROOKX, y, IMAGE_WhiteRook);
			pieces.push_back(new Rook(rook));
			rook.SetXY(FROOKX, y + 80 * 7, IMAGE_BlackRook);
			pieces.push_back(new Rook(rook));
			rook.SetXY(SROOKX, y + 80 * 7, IMAGE_BlackRook);
			pieces.push_back(new Rook(rook));
			break;
		case _bishop: 
			bishop.SetXY(FBISHOPX, y, IMAGE_WhiteBishop);
			pieces.push_back(new BiShop(bishop));
			bishop.SetXY(SBISHOPX, y, IMAGE_WhiteBishop);
			pieces.push_back(new BiShop(bishop));
			bishop.SetXY(FBISHOPX, y + 80 * 7, IMAGE_BlackBishop);
			pieces.push_back(new BiShop(bishop));
			bishop.SetXY(SBISHOPX, y + 80 * 7, IMAGE_BlackBishop);
			pieces.push_back(new BiShop(bishop));
			break;
		}
	}

}
page GameManager::PageCheck() {//페이지확인

	return (page)CurrStatue;
}
void GameManager::GameStart()//게임이 시작될경우 카드세팅
{
	if (CurrStatue == MAIN)
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
	
	for (int i = 0;  i < 64; i++)
	{
		tiles[i].Draw(hdc, (CHECKIMAGE)3, false);
	}
	for (auto iter = pieces.begin(); iter < pieces.end(); iter++)
	{
		(*iter)->Draw(hdc, (CHECKIMAGE)4);
	}
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
		CurrStatue = MAIN;
}

bool GameManager::ColliderCheck(POINT point,HWND hwnd)//화면에서 이미지 눌렀는지확인
{
	switch (CurrStatue)
	{
	case MAIN:
		if (PtInRect(&startRect, point))
		{
			GameStart();
			return true;
		}
		break;
	case End:
		if (PtInRect(&tryAgain, point))
		{
			GoHome();
			return true;
		}
		break;
	default:
		if (piecesmove == false)
		{
			for (auto iter = pieces.begin(); iter < pieces.end(); iter++)
			{
				if ((*iter)->ColliderCheck(point)) // 해당기물이 선택되었다면 초록색 범위의 타일 그리기
				{
					if ((*iter)->SetMove(tiles, pieces))
					{
						piecesmove = true;
						return true;
					}
				}
			}
			return true;
		}
		else
		{
			for (int i = 0; i < 64; i++)
			{
				if (tiles[i].ColliderCheck(point))//타일을 반복문을 통해 클릭이 되었을떄 해당 타일이 피스가 움직일수있는 범위의 타일중 하나이면
				{
					for (auto iter = pieces.begin(); iter < pieces.end(); iter++)
					{
						if ((*iter)->CheckSelect()) 
						{
							(*iter)->Move(tiles[i].GetTx(), tiles[i].GetTy(),tiles);// 좌표 변환
							piecesmove = false;

							return true;
						}

					}
				}
			}
		}
	}
	return false;

	 
}
void GameManager::Init(HWND hWnd)
{
	BitMapManager::GetInstance()->Init(hWnd);
}
