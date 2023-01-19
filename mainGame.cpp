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
		if (A->retPy() >1)
		{
			A->Sety(-1);
		}
		break;
	case 75://왼쪽화살표
		if (A->retPx() > 1)
		{
			A->Setx(-1);
		}
		break;
	case 77://오른쪽화살표
		if (A->retPx() < 18)
		{
			A->Setx(1);
			
		}
		break;
	case 80://아래화살표
		if (A->retPy() < 18)
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
			stoneList->push_back({ F, A->retPx(), A->retPy() });
		}
		A->EndTurn();
		break;
	}


}

int MainGame::WinCheck(int wincheck[45][90],int width,int height)//승리함수체크
{
	for (int x = 0; x < width; x++)
	{
		for(int y = 0; y < height; y++)
		{
			if (wincheck[y][x] == 1)
			{

				if (wincheck[y][x] == wincheck[y][x + 1] == wincheck[y][x + 2] == wincheck[y][x + 3] == wincheck[y][x + 4]==F)//가로
				{
					return F;
				}
				else if (wincheck[y][x] == wincheck[y + 1][x] == wincheck[y + 1][x] == wincheck[y + 1][x] == wincheck[y + 1][x]==F)//세로
				{
					return F;
				}
				else if (wincheck[y][x] == wincheck[y + 1][x+1] == wincheck[y + 2][x+2] == wincheck[y + 3][x+3] == wincheck[y + 4][x+4]==F)//오른쪽대각선
				{
					return F;
				}
				else if (wincheck[y][x] == wincheck[y + 1][x - 1] == wincheck[y + 2][x - 2] == wincheck[y + 3][x - 3] == wincheck[y + 4][x - 4]==F)//왼쪽 대각선
				{
					return F;
				}

			}
			else if(wincheck[y][x] == 2)
			{


				if (wincheck[y][x] == wincheck[y][x + 1] == wincheck[y][x + 2] == wincheck[y][x + 3] == wincheck[y][x + 4]==S)//가로
				{
					return S;
				}
				else if (wincheck[y][x] == wincheck[y + 1][x] == wincheck[y + 1][x] == wincheck[y + 1][x] == wincheck[y + 1][x]==S)//세로
				{
					return S;
				}
				else if (wincheck[y][x] == wincheck[y + 1][x + 1] == wincheck[y + 2][x + 2] == wincheck[y + 3][x + 3] == wincheck[y + 4][x + 4]==S)//오른쪽대각선
				{
					return S;
				}
				else if (wincheck[y][x] == wincheck[y + 1][x - 1] == wincheck[y + 2][x - 2] == wincheck[y + 3][x - 3] == wincheck[y + 4][x - 4]==S)//왼쪽 대각선
				{
					return S;
				}



			}

		}
	}
	return 0;
	
}

