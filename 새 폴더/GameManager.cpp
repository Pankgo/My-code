#include "GameManager.h"

GameManager* GameManager::GameM = NULL;

GameManager::GameManager()
{
	BackGround = BitMapManager::GetInstance()->GetImage(IMAGE_BACKGROUND); //��׶��� �̹��� ����
	startbutton = BitMapManager::GetInstance()->GetImage(IMAGE_STARTBUTTON);//���۹�ư����
	tryagain = BitMapManager::GetInstance()->GetImage(IMAGE_STARTBUTTON);//���۹�ư����
	
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

	Getxy getxy;//����ü ����
	
	for (int x = 50, i = 0; i < 4; i++, x += 100)//ī����Ӿ��� ī��� xy��ǥ ���Ϳ� ����
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

page GameManager::PageCheck() {//������Ȯ��
	if (CurrStatue == Start)
		return Start;
	return Game;
}
void GameManager::GameStart()//������ ���۵ɰ�� ī�弼��
{
	if (CurrStatue == Start)
		CurrStatue = Game;

	Card card1;
	int set = 0;
	int randxy;//xy��ǥ �ε��� ���庯��
	int imagecount = 0;//���� �̹����� 2�� ������ �˻�
	IMAGE image;
	bool xycount = true;

	std::vector<IMAGE> images;

	int removeImage[2]; 
	int randnum;
	removeImage[0] = rand() % IMAGE_COUNT;
	
	while (1) // �̹���10���� �������� 2�廩��
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

	for (int i = IMAGE_START; IMAGE_COUNT > i; i++) // �̹��� ����
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

	for (auto iter = cards.begin(); iter < cards.end(); iter++)//�ݺ��ڸ� ���� �ߺ� ���� Ȯ��
	{
		iter->Draw(hdc, CARDIMAGE);
	}
}
void GameManager::EndP(HDC hdc) // ���â ����
{
	tryagain->Draw(hdc, try_x, try_y, TRY);
}
GameManager::~GameManager()
{

}

void GameManager::CardCheck(POINT point)//ī��üũ
{

	for (int i = 0 ; cards.size() > i; i++)
	{
		if (cards[i].ColliderCheck(point))
		{
			if (nullptr == select1) { select1 = &cards[i]; select1->ChangeState(true); }
			else
			{
				select2 = &cards[i];
				select2->ChangeState(true);
				if (select1->CheckBitMap() == select2->CheckBitMap()) // ���� �̹������� Ȯ��
				{
					select1 = nullptr;
					select2 = nullptr;
				}
				else
				{
					float oldclock = clock();
					float newclock;

					gamestop = true;
					while (1)
					{
						newclock = clock();
						if (newclock - oldclock > 2000)
						{
							break;
						}
					}
				}
			}
			break;
		}
	}


	
}
void GameManager::GameStop()
{
	select1->ChangeState(false);
	select2->ChangeState(false);
	// ���õ� �� ī�� �޸����� ������
	select1 = nullptr;
	select2 = nullptr;
}
bool GameManager::ColliderCheck(POINT point,page page)//ȭ�鿡�� �̹��� ��������Ȯ��
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
