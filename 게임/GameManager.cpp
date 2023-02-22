#include "GameManager.h"
#include "Dongeon.h"

GameManager::GameManager()
{
	UIDraw();
}
void GameManager::MainMenu() // 수정
{
	cout << "☆★DonGeonRpg★☆\n\n\n";
	cout << "1. 게임시작\n\n";
	cout << "2. 게임불러오기\n\n";
	cout << "3. 나가기";
}
void GameManager::SubMenu()// 수정
{
	cout << "☆★DonGeonRpg★☆\n\n\n";
	cout << "플레이어 이름 : " << player.retName() << endl;
	cout << "1. 던전 입장\n\n";
	cout << "2. 무기 상점\n\n";
	cout << "3. 나가기";
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
		cout << "플레이어 이름을 적으세요 : ";
		cin >> Name;
		player.SetName(Name);
	}
	while (1)
	{
	
		system("cls");
		SubMenu();//메인 게임 안의 ui 출력
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
void GameManager::LoadGame()//파일 불러오기;
{
	system("cls");
	int x = Game_Width / 2;
	int y = 10;
	ifstream Load;
	string _str;
	int select;
	int _int;

	for (int i = 0; i < 5; i++)//파일 배열의 인덱스 데이터를 확인하여 있을경우 yes, 없을 경우 No 로 출력
	{
		gotoxy(x, y+i);
		cout << "파일" << i + 1 << " : ";
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
		Load.open("세이브1");
		break;
	case 2:
		Load.open("세이브2");
		break;
	case 3:
		Load.open("세이브3");
		break;
	case 4:
		Load.open("세이브4");
		break;
	case 5:
		Load.open("세이브5");
		break;
	case 6:
		Load.open("세이브6");
		break;
	}
	if (Load.is_open())
	{
		player.load(Load);
	}
	else
	{
		system("cls");
		cout << "파일 불러오기 실패!";
		system("pause");
	}
	Load.close();


}