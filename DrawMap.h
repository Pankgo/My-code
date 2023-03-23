#pragma once
#include"Master.h"

class DrawMap
{
    int map_width = 80 ,map_height = 50;//������ ��ü���� x,y
    int box_width = 10, box_height = 5;//�ؽ�Ʈ �ڽ� ����, ����
public:
    //DrawMap();
    void gotoxy(int x, int y)
    {
        COORD Cur;
        Cur.X = x;
        Cur.Y = y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
    }

    void DrawBox()//��ü �ʱ׸���
    {
        for (int y = 0; y < map_height; y++)
        {
            //for (int x = 0; x < map_width; x++)
            {
                gotoxy(2, 2);
                if (y == 0)
                {
                    cout << "��";
                    for (int x = 0; x <40; x++)
                        cout << "��";
                    cout << "��";
                }
                /*else if (y == map_height - 1)
                {
                    cout << "��";
                    for (int x = 1; x < map_width - 1; x++)
                        cout << "��";
                    cout << "��";
                }
                else
                {
                    cout << "��";
                    for (int x = 1; x < map_width - 1; x++)
                        cout << "  ";
                    cout << "��";
                }*/
            }
        }
    }
    void DrawTextBox()
    {
        int boxp_x = map_width / 2 -10, boxp_y = map_height / 2 -10;//�ڽ� ��ġ 
        for (int y = 0; y < box_height; y++)
        {
            for (int x = 0; x < box_width; x++)
            {
                gotoxy(boxp_x + x, boxp_y + y);
                if (y == 0)
                {
                    cout << "��";
                    for (int x = 1; x < box_width - 1; x++)
                        cout << "��";
                    cout << "��";
                }
                else if (y == box_height - 1)
                {
                    cout << "��";
                    for (int x = 1; x < box_width - 1; x++)
                        cout << "��";
                    cout << "��";
                }
                else
                {
                    cout << "��";
                    for (int x = 1; x < box_width - 1; x++)
                        cout << "  ";
                    cout << "��";
                }
            }
        }
    }

};

void MapDraw::BoxDraw(int Start_x, int Start_y, int Width, int Height)
{
    if (Start_x > Width)
        Start_x -= Width;
    for (int y = 0; y < Height; y++)
    {
        gotoxy(Start_x, Start_y + y);
        if (y == 0)
        {
            cout << "��";
            for (int x = 1; x < Width - 1; x++)
                cout << "��";
            cout << "��";
        }
        else if (y == Height - 1)
        {
            cout << "��";
            for (int x = 1; x < Width - 1; x++)
                cout << "��";
            cout << "��";
        }
        else
        {
            cout << "��";
            for (int x = 1; x < Width - 1; x++)
                cout << "  ";
            cout << "��";
        }
    }
    return;
}