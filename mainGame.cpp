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
	MapDraw::GameMapDraw(0, 0, (int)GameSet::retWidth(), (int)GameSet::retHeight());//�ʱ�ʱ׸���
	switch (playerType) {
	case F:
		MapDraw::DrawPoint("��", (int)PlayerInfo::retPx(), (int)PlayerInfo::retPy());
		break;
	case S:
		MapDraw::DrawPoint("��", (int)PlayerInfo::retPx(), (int)PlayerInfo::retPy());
		break;
	}//�ʱ� �÷��̾� ����Ʈ �׸���
	while (1)//�����϶����� �� ������Ʈ
	{
		if(kbhit())
		{
			int character = getch();
			switch (character)
			{
			case 72://��ȭ��ǥ
				PlayerInfo::Suby(1);
				break;
			case 75://����ȭ��ǥ
				PlayerInfo::Subx(1);
				break;
			case 77://������ȭ��ǥ
				PlayerInfo::Plusx(1);
				break;
			case 80://�Ʒ�ȭ��ǥ
				PlayerInfo::Plusy(1);
			case 32://�����̽���
				player_turn = 1;
				break;
			}
			MapDraw::UpdateMapDraw((int)GameSet::retWidth(), (int)GameSet::retHeight(), (int)PlayerInfo::retPx(), (int)PlayerInfo::retPy());//������Ʈ �� �� �׷��ִ� �Լ�
			continue;
		}
		else if (player_turn == 1)
		{
			player_turn = 0;

			break;
		}

	}

}
