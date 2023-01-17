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
	MapDraw::GameMapDraw(0, 0,);//초기맵그리기
	switch (playerType) {
	case F:
		MapDraw::DrawPoint("●", p1->retPx(), p1->retPy());
		break;
	case S:
		MapDraw::DrawPoint("○", p2->retPx(), p2->retPy());
		break;
	}//초기 플레이어 포인트 그리기
	while (1)//움직일때마다 맵 업데이트
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

void MainGame::CMove(PlayerInfo* A,int move,int character)//캐릭터동작함수
{

	switch (move)
	{
	case 72://윗화살표
		A->Suby(1);
		break;
	case 75://왼쪽화살표
		A->Subx(1);
		break;
	case 77://오른쪽화살표
		A->Plusx(1);
		break;
	case 80://아래화살표
		A->Plusy(1);
	case 32://스페이스바
		break;
	}


}
