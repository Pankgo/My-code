#include "MainGame.h"

enum Player
{
	First=1,
	Second
};
enum Check
{
	No,
	Yes
};
MainGame::MainGame()
{


}




void MainGame::Mainplay(int playerType,PlayerInfo *A,PlayerInfo *B,vector<Point>*stoneList)
{
	PlayerInfo* info;
	switch (playerType) {
	case First: info = A;
		//MapDraw::DrawPoint(A->RetMouse(), A->retPx(), A->retPy());
		break;
	case Second:
		info = B;
		//MapDraw::DrawPoint(B->RetMouse(), B->retPx(), B->retPy());
		break;
	}//초기 플레이어 포인트 그리기
	MapDraw::DrawPoint(info->RetMouse(), info->retPx(), info->retPy());

	while (1)//움직일때마다 맵 업데이트
	{
		if (_kbhit())
		{
			int character = _getch();
			CMove(playerType, info, character, stoneList);

			/*if (playerType == First)
			{
				CMove(playerType,A, character,stoneList);
			}
			else {
				CMove(playerType,B, character,stoneList);
			}*/
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
		stoneList->push_back({ playerType, A->retPx(), A->retPy() });
		A->EndTurn();
		break;
	case 98 : //무르기
		if (A->RetBack() != 0)
		{
			A->Back();
			A->EndTurn();
			auto iter = stoneList->end() - 1;
			stoneList->erase(iter);
			break;
		}

		break;
	}


}

int MainGame::WinCheck(vector<Point> stoneList, int wincheck[45][90], int width, int height)//승리함수체크
{
	for (int y = 1; y < height; y++)
	{
		for(int x = 1; x < width; x++)
		{
			if (wincheck[y][x] == First)
			{

				if (MainGame::WinRightCheck(y,x,wincheck,First) == Yes)//가로
				{
					return First;
				}
				else if (MainGame::WinLeftCheck(y,x,wincheck,First) == Yes)//세로
				{
					return First;
				}
				else if (MainGame::WinRightDiagonalCheck(y,x,wincheck,First) == Yes )//오른쪽대각선
				{
					return First;
				}
				else if (MainGame::WinLeftDiagonalCheck(y, x, wincheck, First) == Yes)//왼쪽 대각선
				{
					return First;
				}

			}
			else if(wincheck[y][x] == Second)
			{


				if (MainGame::WinRightCheck(y, x, wincheck, Second) == Yes)//가로
				{
					return Second;
				}
				else if (MainGame::WinLeftCheck(y, x, wincheck, Second) == Yes)//세로
				{
					return Second;
				}
				else if (MainGame::WinRightDiagonalCheck(y, x, wincheck, Second) == Yes)//오른쪽대각선
				{
					return Second;
				}
				else if (MainGame::WinLeftDiagonalCheck(y, x, wincheck, Second) == Yes)//왼쪽 대각선
				{
					return Second;
				}



			}

		}
	}
	return 0;
	
}

int MainGame::WinRightCheck(int y, int x, int wincheck[45][90],int sequence)//가로
{
	if(wincheck[y][x] == sequence && wincheck[y][x + 1] == sequence && wincheck[y][x + 2] == sequence && wincheck[y][x + 3] == sequence && wincheck[y][x + 4] == sequence)
	{
		return Yes;
	}
	return No;
}
int MainGame::WinLeftCheck(int y, int x, int wincheck[45][90], int sequence)//세로
{
	if(wincheck[y][x] == sequence && wincheck[y + 1][x] == sequence && wincheck[y + 2][x] == sequence && wincheck[y + 3][x] == sequence && wincheck[y + 4][x] == sequence)
	{
		return Yes;
	}
	return No;
}
int MainGame::WinRightDiagonalCheck(int y, int x, int wincheck[45][90], int sequence)//오른쪽대각선
{
	if(wincheck[y][x] == sequence && wincheck[y + 1][x + 1] == sequence && wincheck[y + 2][x + 2] == sequence && wincheck[y + 3][x + 3] == sequence && wincheck[y + 4][x + 4] == sequence)
	{
		return Yes;
	}
	return No;
}
int MainGame::WinLeftDiagonalCheck(int y, int x, int wincheck[45][90], int sequence)//왼쪽 대각선
{
	if (wincheck[y][x] == sequence && wincheck[y + 1][x - 1] == sequence && wincheck[y + 2][x - 2] == sequence && wincheck[y + 3][x - 3] == sequence && wincheck[y + 4][x - 4] == sequence)
	{
		return Yes;
	}
	return No;
}

