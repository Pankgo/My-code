#include "MainGame.h"


Game::Game()
{

	

}




void Game::Mainplay()
{
	int player_turn = 0;
	while (1)
	{
		MapDraw::GameMapDraw(0, 0, 20, 20);
		MapDraw::DrawPoint("��", start_x, start_y);
		if(kbhit())
		{
			int character = getch();
			switch (character)
			{
			case 72://��ȭ��ǥ
				start_y -=1;
				break;
			case 75://����ȭ��ǥ
				start_x -= 1;
				break;
			case 77://������ȭ��ǥ
				start_x += 1;
				break;
			case 80://�Ʒ�ȭ��ǥ
				start_y += 1;
			case 32://�����̽���
				int player_turn = 1;
				break;
			}
		}
		if (player_turn == 1)
		{
			player_turn = 0;



		}

	}

}