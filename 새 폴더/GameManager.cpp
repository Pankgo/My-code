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

	while(set < NORMAL*2) // ī�� ����
	{
		switch (imagecount)
		{
		case 0:
			image = IMAGE(rand() % 10);
			if (find(checkcards.begin(), checkcards.end(), image) != checkcards.end()) { continue; }//�ߺ��̹��������� ��� �ٽ� �̱�
			checkcards.push_back(image);
			break;

		}
		while (1)//xy���Ϳ��� ��ġ�̾Ƴ���
		{
			randxy = rand() % 16; //xy���Ϳ��� ������ �ε��� 
			for (auto iter = cards.begin(); iter < cards.end(); iter++)//�ݺ��ڸ� ���� �ߺ� ���� Ȯ��
			{
				if (iter->GetX() == xy[randxy].x)
				{
					if (iter->GetY() == xy[randxy].y)
					{
						xycount = false;
						break;//������ϸ� �ٽ�
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
		//�̹��� �ε���
		card1.Init(image, xy[randxy].x, xy[randxy].y);
		
	
		cards.push_back(card1);//����ϸ� ����
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
void GameManager::PageDraw(HDC hdc)//������ Ȯ�� �� �׷�����
{
	BackGround->Draw(hdc, Back_X, Back_y,BACKGROUND);
	if (CurrStatue == Start)
		StartP(hdc);
	else if (CurrStatue == Game)
		GameP(hdc);
	else
		EndP(hdc);
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
	bool result = false;
	int cardcount = 0;


	for (auto iter1 = cards.begin(); iter1 < cards.end() && result == false; iter1++)
	{
		if (iter1->ColliderCheck(point))//�̹��� ���� �ִ��� Ȯ��
		{
			for (auto iter2 = cards.begin(); iter2 < cards.end() && result == false; iter2++)//���� ���� ī�尡 2�� �� ���µǾ�������� �ȵ�������
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
