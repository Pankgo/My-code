#include "MainGame.h"

enum Player
{
	F=1,
	S
};
Game::Game()
{
	PlayerInfo p1;
	PlayerInfo p2;
	while (1)
	{
		Mainplay(F);
		Mainplay(S);
	}



}




void Game::Mainplay(int playerType)
{
	int player_turn = 0;
	int player_x = 
	MapDraw::GameMapDraw(0, 0, (int)GameSet::retWidth(), (int)GameSet::retHeight());//초기맵그리기
	switch (playerType) {
	case F:
		MapDraw::DrawPoint("●", (int)PlayerInfo::retPx(), (int)PlayerInfo::retPy());
		break;
	case S:
		MapDraw::DrawPoint("●", (int)PlayerInfo::retPx(), (int)PlayerInfo::retPy());
		break;
	}//초기 플레이어 포인트 그리기
	while (1)//움직일때마다 맵 업데이트
	{
		if(kbhit())
		{
			int character = getch();
			switch (character)
			{
			case 72://윗화살표
				PlayerInfo::Suby(1);
				break;
			case 75://왼쪽화살표
				PlayerInfo::Subx(1);
				break;
			case 77://오른쪽화살표
				PlayerInfo::Plusx(1);
				break;
			case 80://아래화살표
				PlayerInfo::Plusy(1);
			case 32://스페이스바
				player_turn = 1;
				break;
			}
			MapDraw::UpdateMapDraw((int)GameSet::retWidth(), (int)GameSet::retHeight(), (int)PlayerInfo::retPx(), (int)PlayerInfo::retPy());//업데이트 된 맵 그려주는 함수
			continue;
		}
		else if (player_turn == 1)
		{
			player_turn = 0;

			break;
		}

	}

}
