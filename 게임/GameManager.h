#include "Mecro.h"
#include "Character.h"
#include "Monster.h"
#include "Dongeon.h"

enum CheckSave
{
	NonSave,
	Save
};
enum GameSelect
{
	Start =1,
	Shop,
	Return

};
class GameManager
{
	Player player;
	Dongeon dongeon;
	int File[6] = {0};
	int Game_Height = 100;
	int Game_Width = 100;
public:
	GameManager();
	void UIDraw();// ���� �����ϱ��� ����ȭ�� �����
	void StartGame();//���� �����ϱ�
	void LoadGame();//���Ϻҷ�����
	void UsingShop();//����
	void Dongeon();//����
	void MainMenu();
	void SubMenu();
	inline void gotoxy(int x, int y)
	{
		COORD Pos = { x, y };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
	}


};