#include "Merch.h"
#include "Block.h"
#include "Snake.h"

enum play
{
	Start = 1,
	End
};


class Gamemanager
{
	int insideWall = 10;
	Block block;
	SnakeInfo snake;
	int map_Width = 40;
	int map_Height = 30;
	int map[30][40];

public:
	Gamemanager();
	void MapDraw();//�ʱ׸���
	void GamePlay();//�����÷���
	void UIDraw();//�ʱ� ����ȭ��
	void Menu(); // �޴�
	void CheckCrash();//�浹Ȯ��



};