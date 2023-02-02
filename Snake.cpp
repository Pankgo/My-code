#include "Snake.h"

void SnakeInfo::Snakemove(char ch)
{
	int oldclock = clock();
	while (1)
	{
		int curClock = clock();
		if (curClock - oldclock >= 1000)
		{
			switch (ch)
			{
			case 'w':
				oldDirection = 'w';
				SetSnakePosY(-1);
				break;
			case 'a':
				oldDirection = 'a';
				SetSnakePosX(-1);
				break;
			case 's':
				oldDirection = 's';
				SetSnakePosY(1);
				break;
			case 'd':
				oldDirection = 'd';
				SetSnakePosX(1);
				break;
			}
		}
	}
}

