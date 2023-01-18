#include "MainGame.h"

enum Player
{
	F=1,
	S
};
MainGame::MainGame()
{


}




void MainGame::Mainplay(int playerType,PlayerInfo *A,PlayerInfo *B,vector<Point>stoneList)
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
				CMove(A, character,stoneList);
			}
			else {
				CMove(B, character,stoneList);
			}
			break;
		}
		continue;
		
	}

}

void MainGame::CMove(PlayerInfo* A,int move, vector<Point> stoneList)//ĳ���͵����Լ�
{

	switch (move)
	{
	case 72://��ȭ��ǥ
		A->Suby(1);
		break;
	case 75://����ȭ��ǥ
		A->Subx(1);
		break;
	case 77://������ȭ��ǥ
		A->Plusx(1);
		break;
	case 80://�Ʒ�ȭ��ǥ
		A->Plusy(1);
		break;
	case 32://�����̽��� ������
		stoneList.push_back({ F, A->retPx(), A->retPy() });
		A->EndTurn();
		break;
	}


}
