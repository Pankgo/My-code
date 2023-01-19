#include "MainGame.h"

enum Player
{
	F=1,
	S
};
MainGame::MainGame()
{


}




void MainGame::Mainplay(int playerType,PlayerInfo *A,PlayerInfo *B,vector<Point>*stoneList)
{
	int player_turn = 0;
	switch (playerType) {
	case F:
		MapDraw::DrawPoint("��", A->retPx(), A->retPy());
		break;
	case S:
		MapDraw::DrawPoint("��", B->retPx(), B->retPy());
		break;
	}//�ʱ� �÷��̾� ����Ʈ �׸���
	while (1)//�����϶����� �� ������Ʈ
	{
		if (_kbhit())
		{
			int character = _getch();
			if (playerType == F)
			{
				CMove(playerType,A, character,stoneList);
			}
			else {
				CMove(playerType,B, character,stoneList);
			}
			break;
		}
		continue;
		
	}

}

void MainGame::CMove(int playerType,PlayerInfo* A,int move, vector<Point> *stoneList)//ĳ���͵����Լ�
{

	switch (move)
	{
	case 72://��ȭ��ǥ
		if (A->retPy() >0 )
		{
			A->Sety(-1);
		}
		break;
	case 75://����ȭ��ǥ
		if (A->retPx() > 0)
		{
			A->Setx(-1);
		}
		break;
	case 77://������ȭ��ǥ
		if (A->retPx() < 20)
		{
			A->Setx(1);
			
		}
		break;
	case 80://�Ʒ�ȭ��ǥ
		if (A->retPy() < 20)
		{
			A->Sety(1);

		}
		break;
	case 32://�����̽��� ������
		if (playerType == F)
		{
			stoneList->push_back({ F, A->retPx(), A->retPy() });
		}
		else
		{
			stoneList->push_back({ S, A->retPx(), A->retPy() });
		}
		A->EndTurn();
		break;
	}


}
