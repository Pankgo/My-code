#include "GameManager.h"

GameManager* GameManager::GameM = NULL;

GameManager::GameManager()
{
	BackGround = BitMapManager::GetInstance()->GetImage(IMAGE_BACKGROUND); //��׶��� �̹��� ����
	startbutton = BitMapManager::GetInstance()->GetImage(IMAGE_STARTBUTTON);//���۹�ư����
	tryagain = BitMapManager::GetInstance()->GetImage(IMAGE_TRY);//���۹�ư����

	
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
void GameManager::TilesSet() // Ÿ�ϼ���
{
	tile starttile;
	Tiles newtile;
	int start = 0;

	for (int x = 0, i = 0; i < 8; i++, x += 80)//Ÿ�� ����
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

void GameManager::PiecesSet() // �ǽ�����
{
	King king;
	Queen queen;
	Horse horse;
	Rook rook;
	BiShop bishop;
	Pawn pawn;

	int x = 0, y = 80; // ȭ��Ʈ �� �ʱ� ��ġ
	IMAGE startcolor = IMAGE_WhitePawn;
	for (int pawn_count = 0; pawn_count < 16; pawn_count++) // �� �̹��� �� ��ġ ����
	{
		if (pawn_count == 8)
		{
			x = 0; y = 480; //�� �� �ʱ���ġ
			startcolor = IMAGE_BlackPawn;
		}
		pawn.SetXY(x, y, startcolor);
		pieces.push_back(new Pawn(pawn));
		x += 80;
	}
	x = 0; y = 0;
	for (int pieces_count = 0; pieces_count < 5; pieces_count++) // ������ �⹰�� �̹��� �� ��ġ ����
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
page GameManager::PageCheck() {//������Ȯ��

	return (page)CurrStatue;
}
void GameManager::GameStart()//������ ���۵ɰ�� ī�弼��
{
	if (CurrStatue == MAIN)
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
	
	for (int i = 0;  i < 64; i++)
	{
		tiles[i].Draw(hdc, (CHECKIMAGE)3, false);
	}
	for (auto iter = pieces.begin(); iter < pieces.end(); iter++)
	{
		(*iter)->Draw(hdc, (CHECKIMAGE)4);
	}
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
		CurrStatue = MAIN;
}

bool GameManager::ColliderCheck(POINT point,HWND hwnd)//ȭ�鿡�� �̹��� ��������Ȯ��
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
				if ((*iter)->ColliderCheck(point)) // �ش�⹰�� ���õǾ��ٸ� �ʷϻ� ������ Ÿ�� �׸���
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
				if (tiles[i].ColliderCheck(point))//Ÿ���� �ݺ����� ���� Ŭ���� �Ǿ����� �ش� Ÿ���� �ǽ��� �����ϼ��ִ� ������ Ÿ���� �ϳ��̸�
				{
					for (auto iter = pieces.begin(); iter < pieces.end(); iter++)
					{
						if ((*iter)->CheckSelect()) 
						{
							(*iter)->Move(tiles[i].GetTx(), tiles[i].GetTy(),tiles);// ��ǥ ��ȯ
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
