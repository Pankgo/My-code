#include "MainGame.h"

enum Player
{
	F=1,
	S
};
MainGame::MainGame()
{
	while (1)
	{
		Mainplay(F);
		Mainplay(S);
	}



}




void MainGame::Mainplay(int playerType)
{
	int player_turn = 0;
	int player_x;
	MapDraw::GameMapDraw(0, 0,);//�ʱ�ʱ׸���
	switch (playerType) {
	case F:
		MapDraw::DrawPoint("��", p1->retPx(), p1->retPy());
		break;
	case S:
		MapDraw::DrawPoint("��", p2->retPx(), p2->retPy());
		break;
	}//�ʱ� �÷��̾� ����Ʈ �׸���
	while (1)//�����϶����� �� ������Ʈ
	{
		if(kbhit())
		{
			int character = getch();
			switch (playerType)
			{
			case F:
				CMove(p1, character,playerType);
				break;
			case S:
				CMove(p2, character,playerType);
			}
			continue;
		}
		else if (player_turn == 1)
		{
			player_turn = 0;

			break;
		}

	}

}

void MainGame::CMove(PlayerInfo* A,int move,int character)//ĳ���͵����Լ�
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
	case 32://�����̽���
		break;
	}


}
