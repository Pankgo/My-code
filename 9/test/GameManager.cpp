#include "GameManager.h"
#include "Dongeon.h"

GameManager::GameManager()
{
	ifstream save1;//���� �����˻�

	save1.open("���̺�1.txt");
	if (save1.is_open())
	{
		File[0] = Save;
	}
	save1.close();
	save1.open("���̺�2.txt");
	if (save1.is_open())
	{
		File[1] = Save;
	}
	save1.close();
	save1.open("���̺�3.txt");
	if (save1.is_open())
	{
		File[2] = Save;
	}
	save1.close();
	save1.open("���̺�4.txt");
	if (save1.is_open())
	{
		File[3] = Save;
	}
	save1.close();
	save1.open("���̺�5.txt");
	if (save1.is_open())
	{
		File[4] = Save;
	}
	save1.close();
	save1.open("���̺�6.txt");
	if (save1.is_open())
	{
		File[5] = Save;
	}
	save1.close();
	UIDraw();
}
void GameManager::MainMenu() // ����
{
	int x = WIDTH / 2;
	int y = 5;

	mapDraw.TextDraw("�١�DonGeonRpg�ڡ�", x, y);
	mapDraw.TextDraw("1. ���� ����", x, y += 3);
	mapDraw.TextDraw("2. ������ ", x, y += 3); 
}
void GameManager::SubMenu()// ����
{
	int x = WIDTH / 2;
	int y = 2;

	mapDraw.TextDraw("�١�DonGeonRpg�ڡ�",x,y);
	mapDraw.TextDraw("�÷��̾� �̸� : ",x,y+=3); cout << player.retName() << endl;
	mapDraw.TextDraw("������ : ", x, y += 3); cout << player.retMoney() << endl;
	mapDraw.TextDraw("���� ����ġ : ", x, y += 3); cout << player.retExp() <<"{���� ����ġ(" << 100-player.retExp()%100 <<")}" << endl;
	mapDraw.TextDraw("���� ���� : ", x, y += 3); cout << player.retWeapon() << endl;
	mapDraw.TextDraw("���� ���� : ", x, y += 3); cout << player.retLevel() << endl;
	mapDraw.TextDraw("1.���� ���� ", x, y += 3); 
	mapDraw.TextDraw("2.���� ����  ", x, y += 3);
	mapDraw.TextDraw("3.������  ", x, y += 3); 
	mapDraw.TextDraw("4.�������� ����  ", x, y += 3);
}

void GameManager::UIDraw()
{
	int mainselect;

	while(1)
	{ 
		system("cls");
		MainMenu();
		switch (mapDraw.MenuSelectCursor(2, 3, 5, 8)) // 5->x��ǥ 8 -> y��ǥ, ù��° 3-> �޴��ִ���� �ι�° 3-> ��ǥ ����(y��)
		{
		case 1:
			if(LoadGame() ==false)
			{
				break;
			}
			else
			{
				StartGame();
			}
			break;
		case 2:
			return;
		}
	}

}

void GameManager::GameSave()
{
	system("cls");
	int select;
	int x = Game_Width / 2;
	int y = 10;
	ofstream save;

	for (int i = 0; i < 6; i++)//���� �迭�� �ε��� �����͸� Ȯ���Ͽ� ������� yes, ���� ��� No �� ���
	{
		mapDraw.gotoxy(x, y + i);
		cout << "����" << i + 1 << " : ";
		if (File[i] == NonSave)
		{
			cout << "No" << endl;
		}
		else
		{
			cout << "Yes" << endl;
		}
	}
	mapDraw.TextDraw("->�ڷ� ����", x, y + 6);
	select = mapDraw.MenuSelectCursor(7, 1, 20, y);
	switch (select)
	{
	case 1:
		save.open("���̺�1.txt");
		break;
	case 2:
		save.open("���̺�2.txt");
		break;
	case 3:
		save.open("���̺�3.txt");
		break;
	case 4:
		save.open("���̺�4.txt");
		break;
	case 5:
		save.open("���̺�5.txt");
		break;
	case 6:
		save.open("���̺�6.txt");
		break;
	case 7:
		return;
	}
	File[select-1] = Save;
	if (save.is_open())
	{
		player.Save(save);
	save.close();
	}

}

void GameManager::StartGame()
{
	string Name;
	int select;
	if (player.CheckNew() == true)//�ش������� �÷��̾� �̸��� Ȯ���Ͽ� ���� ��� ���ο� ����ڸ� �Է��ϰԲ��Ѵ�.
	{
		system("cls");
		cout << "�÷��̾� �̸��� �������� : ";
		cin >> Name;
		player.SetName(Name);
	}
	while (1)
	{
	
		system("cls");
		SubMenu();//���� ���� ���� ui ���
		switch (mapDraw.MenuSelectCursor(4,3,5,20))
		{
		case Start:
			dongeon.MainPlay(&player);
			break;
		case Shopping:
			shop.showItem(&player);
			break;
		case Return :
			GameSave();
			return;
		case CurSave:
			GameSave();
			break;
			
		}

	}
}
bool GameManager::LoadGame()//���� �ҷ�����;
{
	int x = Game_Width / 2;
	int y = 10;
	ifstream Load;
	string _str;
	int select;
	int _int;

		system("cls");
		for (int i = 0; i < 6; i++)//���� �迭�� �ε��� �����͸� Ȯ���Ͽ� ������� yes, ���� ��� No �� ���
		{
			mapDraw.gotoxy(x, y + i);
			cout << "����" << i + 1 << " : ";
			if (File[i] == NonSave)
			{
				cout << "No";
			}
			else
			{
				cout << "Yes";
			}
		}
		mapDraw.TextDraw("->�ڷ� ����", x, y + 6);
		mapDraw.TextDraw("->���� ����", x, y + 7);
		select = mapDraw.MenuSelectCursor(7, 1, 20, y);
		//cin >> select;
		switch (select)
		{
		case 1:
			Load.open("���̺�1.txt");
			break;
		case 2:
			Load.open("���̺�2.txt");
			break;
		case 3:
			Load.open("���̺�3.txt");
			break;
		case 4:
			Load.open("���̺�4.txt");
			break;
		case 5:
			Load.open("���̺�5.txt");
			break;
		case 6:
			Load.open("���̺�6.txt");
			break;
		case 7:
			Load.close();
			return false;
		}
		player.load(Load);
	Load.close();
	return true;


}