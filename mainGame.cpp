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
		MapDraw::DrawPoint("●", A->retPx(), A->retPy());
		break;
	case S:
		MapDraw::DrawPoint("○", B->retPx(), B->retPy());
		break;
	}//초기 플레이어 포인트 그리기
	while (1)//움직일때마다 맵 업데이트
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

void MainGame::CMove(int playerType,PlayerInfo* A,int move, vector<Point> *stoneList)//캐릭터동작함수
{

	switch (move)
	{
	case 72://윗화살표
		if (A->retPy() >0 )
		{
			A->Sety(-1);
		}
		break;
	case 75://왼쪽화살표
		if (A->retPx() > 0)
		{
			A->Setx(-1);
		}
		break;
	case 77://오른쪽화살표
		if (A->retPx() < 20)
		{
			A->Setx(1);
			
		}
		break;
	case 80://아래화살표
		if (A->retPy() < 20)
		{
			A->Sety(1);

		}
		break;
	case 32://스페이스바 돌저장
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
