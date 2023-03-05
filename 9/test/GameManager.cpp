#include "GameManager.h"
#include "Dongeon.h"

GameManager::GameManager()
{
	ifstream save1;//파일 유무검사

	save1.open("세이브1.txt");
	if (save1.is_open())
	{
		File[0] = Save;
	}
	save1.close();
	save1.open("세이브2.txt");
	if (save1.is_open())
	{
		File[1] = Save;
	}
	save1.close();
	save1.open("세이브3.txt");
	if (save1.is_open())
	{
		File[2] = Save;
	}
	save1.close();
	save1.open("세이브4.txt");
	if (save1.is_open())
	{
		File[3] = Save;
	}
	save1.close();
	save1.open("세이브5.txt");
	if (save1.is_open())
	{
		File[4] = Save;
	}
	save1.close();
	save1.open("세이브6.txt");
	if (save1.is_open())
	{
		File[5] = Save;
	}
	save1.close();
	UIDraw();
}
void GameManager::MainMenu() // 수정
{
	int x = WIDTH / 2;
	int y = 5;

	mapDraw.TextDraw("☆★DonGeonRpg★☆", x, y);
	mapDraw.TextDraw("1. 게임 시작", x, y += 3);
	mapDraw.TextDraw("2. 나가기 ", x, y += 3); 
}
void GameManager::SubMenu()// 수정
{
	int x = WIDTH / 2;
	int y = 2;

	mapDraw.TextDraw("☆★DonGeonRpg★☆",x,y);
	mapDraw.TextDraw("플레이어 이름 : ",x,y+=3); cout << player.retName() << endl;
	mapDraw.TextDraw("소지금 : ", x, y += 3); cout << player.retMoney() << endl;
	mapDraw.TextDraw("현재 경험치 : ", x, y += 3); cout << player.retExp() <<"{남은 경험치(" << 100-player.retExp()%100 <<")}" << endl;
	mapDraw.TextDraw("현재 무기 : ", x, y += 3); cout << player.retWeapon() << endl;
	mapDraw.TextDraw("현재 레벨 : ", x, y += 3); cout << player.retLevel() << endl;
	mapDraw.TextDraw("1.던전 입장 ", x, y += 3); 
	mapDraw.TextDraw("2.무기 상점  ", x, y += 3);
	mapDraw.TextDraw("3.나가기  ", x, y += 3); 
	mapDraw.TextDraw("4.현재진행 저장  ", x, y += 3);
}

void GameManager::UIDraw()
{
	int mainselect;

	while(1)
	{ 
		system("cls");
		MainMenu();
		switch (mapDraw.MenuSelectCursor(2, 3, 5, 8)) // 5->x좌표 8 -> y좌표, 첫번째 3-> 메뉴최대길이 두번째 3-> 좌표 간격(y축)
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

	for (int i = 0; i < 6; i++)//파일 배열의 인덱스 데이터를 확인하여 있을경우 yes, 없을 경우 No 로 출력
	{
		mapDraw.gotoxy(x, y + i);
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
	mapDraw.TextDraw("->뒤로 가기", x, y + 6);
	select = mapDraw.MenuSelectCursor(7, 1, 20, y);
	switch (select)
	{
	case 1:
		save.open("세이브1.txt");
		break;
	case 2:
		save.open("세이브2.txt");
		break;
	case 3:
		save.open("세이브3.txt");
		break;
	case 4:
		save.open("세이브4.txt");
		break;
	case 5:
		save.open("세이브5.txt");
		break;
	case 6:
		save.open("세이브6.txt");
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
	if (player.CheckNew() == true)//해당파일의 플레이어 이름을 확인하여 없을 경우 새로운 사용자를 입력하게끔한다.
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
bool GameManager::LoadGame()//파일 불러오기;
{
	int x = Game_Width / 2;
	int y = 10;
	ifstream Load;
	string _str;
	int select;
	int _int;

		system("cls");
		for (int i = 0; i < 6; i++)//파일 배열의 인덱스 데이터를 확인하여 있을경우 yes, 없을 경우 No 로 출력
		{
			mapDraw.gotoxy(x, y + i);
			cout << "파일" << i + 1 << " : ";
			if (File[i] == NonSave)
			{
				cout << "No";
			}
			else
			{
				cout << "Yes";
			}
		}
		mapDraw.TextDraw("->뒤로 가기", x, y + 6);
		mapDraw.TextDraw("->새로 시작", x, y + 7);
		select = mapDraw.MenuSelectCursor(7, 1, 20, y);
		//cin >> select;
		switch (select)
		{
		case 1:
			Load.open("세이브1.txt");
			break;
		case 2:
			Load.open("세이브2.txt");
			break;
		case 3:
			Load.open("세이브3.txt");
			break;
		case 4:
			Load.open("세이브4.txt");
			break;
		case 5:
			Load.open("세이브5.txt");
			break;
		case 6:
			Load.open("세이브6.txt");
			break;
		case 7:
			Load.close();
			return false;
		}
		player.load(Load);
	Load.close();
	return true;


}