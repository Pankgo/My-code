#include "GameManager.h"
#include "Dongeon.h"

GameManager::GameManager()
{
	UIDraw();
}
void GameManager::MainMenu() // ����
{
	cout << "�١�DonGeonRpg�ڡ�\n\n\n";
	cout << "1. ���ӽ���\n\n";
	cout << "2. ���Ӻҷ�����\n\n";
	cout << "3. ������";
}
void GameManager::SubMenu()// ����
{
	cout << "�١�DonGeonRpg�ڡ�\n\n\n";
	cout << "�÷��̾� �̸� : " << player.retName() << endl;
	cout << "1. ���� ����\n\n";
	cout << "2. ���� ����\n\n";
	cout << "3. ������";
}

void GameManager::UIDraw()
{
	int mainselect;

	while(1)
	{ 
		system("cls");
		MainMenu();
		cin >> mainselect;
		switch (mainselect)
		{
		case 1:
			StartGame();
			break;
		case 2:
			LoadGame();
			break;
		case 3:
			return;
		}
	}

}

void GameManager::StartGame()
{
	string Name;
	int select;
	if (player.CheckNew() == true)
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
		cin >> select;
		switch (select)
		{
		case Start:
			dongeon.MainPlay(&player);
			break;
		case Shop:
			break;
		case Return :
			return;
		}

	}
}
void GameManager::LoadGame()//���� �ҷ�����;
{
	system("cls");
	int x = Game_Width / 2;
	int y = 10;
	ifstream Load;
	string _str;
	int select;
	int _int;

	for (int i = 0; i < 5; i++)//���� �迭�� �ε��� �����͸� Ȯ���Ͽ� ������� yes, ���� ��� No �� ���
	{
		gotoxy(x, y+i);
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
	cin >> select;
	switch (select)
	{
	case 1:
		Load.open("���̺�1");
		break;
	case 2:
		Load.open("���̺�2");
		break;
	case 3:
		Load.open("���̺�3");
		break;
	case 4:
		Load.open("���̺�4");
		break;
	case 5:
		Load.open("���̺�5");
		break;
	case 6:
		Load.open("���̺�6");
		break;
	}
	if (Load.is_open())
	{
		player.load(Load);
	}
	else
	{
		system("cls");
		cout << "���� �ҷ����� ����!";
		system("pause");
	}
	Load.close();


}