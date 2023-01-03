#include "Square.h"



void setSquare::Set(int _avenue, int _height)
{
	avenue = _avenue;
	height = _height;

}

void setSquare::gotoxy(int x, int y, int Line)
{
	COORD Cur;
	Cur.X = x;
	Cur.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
	putch(Line);
}

void setSquare::Draw()
{
	system("cls");
	CONSOLE_SCREEN_BUFFER_INFO presentCur;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &presentCur);
	int i = 0, j = 0;
	int temp_i = presentCur.dwCursorPosition.X;
	int temp_j = presentCur.dwCursorPosition.Y;

	int max_i = avenue + i;
	int max_j = height + j;

	for (i = i + 1; i < max_i; i++) {
		gotoxy(i, temp_j, 6);
		gotoxy(i, max_j, 6);
	}

	for (j = j + 1; j < max_j; j++) {
		gotoxy(temp_i, j, 5);
		gotoxy(max_i, j, 5);
	}
	gotoxy(temp_i, temp_j, 1);
	gotoxy(max_i, temp_j, 2);
	//gotoxy(temp_i, max_j, 3);
	//gotoxy(max_i, max_j, 4);
	
}