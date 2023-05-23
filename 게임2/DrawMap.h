#pragma once
#include"Master.h"
#define UP 'w'
#define DOWN 's'
#define ENTER 13

class DrawMap
{
    enum skill
    {
        No,
        speedup,
        speeddown,
        doublepoint,
        screenclear,
        gamestop,
    };
    int box_width = 10, box_height = 5;//텍스트 박스 넓이, 높이
public:
    int MenuSelectCursor(int MenuLen, int AddCol, int x, int y)
    {
        int Select = 1;
        RED
            DrawPoint("▷", x, y);
        WHITE
            while (1)
            {
                switch (_getch())
                {
                case UP:
                    if (Select - 1 >= 1)
                    {
                        ErasePoint(x, y);
                        y -= AddCol;
                        Select--;
                    }
                    break;
                case DOWN:
                    if (Select + 1 <= MenuLen)
                    {
                        ErasePoint(x, y);
                        y += AddCol;
                        Select++;
                    }
                    break;
                case ENTER:
                    return Select;
                }
                RED
                    DrawPoint("▷", x, y);
               WHITE
            }
    }
    void gotoxy(int x, int y)
    {
        COORD Cur;
        Cur.X = x;
        Cur.Y = y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
    }
    void ErasePoint(int x, int y)
    {
        gotoxy(x  , y);
        cout << "  ";
        gotoxy(-1, -1);
        return;
    }
    void DrawPoint(string str, int x, int y)
    {
        gotoxy(x , y);
        cout << str;
        gotoxy(-1, -1);
        return;
    }
    void DrawMidText(string str, int x, int y)
    {
        if (x > str.size() / 2)
            x -= str.size() / 2;
        gotoxy(x, y);
        cout << str;
        return;
    }
    void Drawtext(int x,int y, string str,int type)
    {
        switch (type)
        {
        case speedup:
            RED;
            break;
        case speeddown:
            BLUE;
            break;
        case doublepoint:
            PUPPLE;
            break;
        case screenclear:
            GOLD;
            break;
        case gamestop:
            GREEN;
            break;
        default:
            WHITE;
            break;
         }
        gotoxy(x, y);
        cout << str;
        WHITE;
    }
    void DrawBox(int map_width,int map_height)//전체 맵그리기
    {
        for (int y = 0; y < map_height; y++)
        {
            gotoxy(0, 0+y);
                if (y == 0)
                {
                    cout << "┌";
                    for (int x = 0; x <map_width*2 - 4; x++)
                        cout << "─";
                    cout << "┐";
                }
                else if (y == map_height - 1)
                {
                    cout << "└";
                    for (int x = 0; x < map_width*2 - 4; x++)
                        cout << "─";
                    cout << "┘";
                }
                else
                {
                    cout << "│";
                    for (int x = 1; x < map_width - 1; x++)
                        cout << "  ";
                    cout << "│";
                }
        }
    }
    void DrawTextBox(int map_width, int map_height)
    {
        int boxp_x = map_width-15, boxp_y = map_height / 2+5;//박스 위치 

        for (int y = 0; y < box_height; y++)
        {
            for (int x = 0; x < box_width; x++)
            {
                gotoxy(boxp_x, boxp_y + y);
                if (y == 0)
                {
                    cout << "┌";
                    for (int x = 0; x < box_width*2; x++)
                        cout << "─";
                    cout << "┐";
                }
                else if (y == box_height - 1)
                {
                    cout << "└";
                    for (int x = 0; x < box_width*2; x++)
                        cout << "─";
                    cout << "┘";
                }
                else
                {
                    cout << "│";
                    for (int x = 0; x < box_width*2; x++)
                        cout << " ";
                    cout << "│";
                }
            }
        }
    }

};

