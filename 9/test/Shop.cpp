#include "Shop.h"

void Shop::SetData()//���Ͼ��� ������ �з��� ����
{
	
	ifstream load;
	load.open("Item.txt");
	string itemName;
	string itemClassName = "";
	int itemNumber;//������ ���� �ڵ�
	int itemvalue;
	int itemDamage;
	int itemCount = 0;
	int itemClassNumber = 0;
	int result;// �ڵ��ȣ�� Ȯ���ϱ� ���� ����

	while (!load.eof())
	{
		load >> itemClassName;
		load >> itemName;
		load >> itemvalue;
		load >> itemDamage;
		load >> itemNumber;
		result = itemNumber / 100;
		switch (result)
		{
		case Bow:
			BowList[itemCount++].setitem(itemName, itemDamage, itemvalue);
			break;
		case Dagger:
			DaggerList[itemCount++].setitem(itemName, itemDamage, itemvalue);
			break;
		case Sword:
			SwordList[itemCount++].setitem(itemName, itemDamage, itemvalue);
			break;
		case Wand:
			WandList[itemCount++].setitem(itemName, itemDamage, itemvalue);
			break;
		case Hammer:
			HammerList[itemCount++].setitem(itemName, itemDamage, itemvalue);
			break;

		}
		if (itemCount == MaxItemCount)
		{
			itemCount = 0;
		}
	}
	load.close();
}

void Shop::PtrWeapon(int Number)//�������
{
	int x = WIDTH / 2;
	int y = 5;
	system("cls");

	switch (Number)
	{
	case Bow:
		for (int i = 0; i < MaxItemCount; i++)
		{
			map.gotoxy(x, y);
			cout << i+1 << " " << BowList[i].retName() << " ������ : " << BowList[i].retDamage() << " ���� : " << BowList[i].retValue();
			y += 3;
		}
		break;
	case Dagger:
		for (int i = 0; i < MaxItemCount; i++)
		{
			map.gotoxy(x, y);
			cout << i+1 << " " << DaggerList[i].retName() << " ������ : " << DaggerList[i].retDamage() << " ���� : " << DaggerList[i].retValue();
			y += 3;
		}
		break;
	case Sword:
		for (int i = 0; i < MaxItemCount; i++)
		{
			map.gotoxy(x, y);
			cout << i+1 << " " << SwordList[i].retName() << " ������ : " << SwordList[i].retDamage() << " ���� : " << SwordList[i].retValue();
			y += 3;
		}
		break;
	case Wand:
		for (int i = 0; i < MaxItemCount; i++)
		{
			map.gotoxy(x, y);
			cout << i+1 << " " << WandList[i].retName() << " ������ : " << WandList[i].retDamage() << " ���� : " << WandList[i].retValue();
			y += 3;
		}
		break;
	case Hammer:
		for (int i = 0; i < MaxItemCount; i++)
		{
			map.gotoxy(x, y);
			cout << i+1<< " " << HammerList[i].retName() << " ������ : " << HammerList[i].retDamage() << " ���� : " << HammerList[i].retValue();
			y += 3;
		}
		break;
	}
	map.TextDraw("������",x,y);
}
void Shop::ShopMenu()
{
	int x = WIDTH / 2;
	int y = 5;

	map.TextDraw("�١�DonGeonRpg ���� �����ڡ�", x, y);
	map.TextDraw("1. Bow", x+5, y += 3);
	map.TextDraw("2. Dagger ", x+5, y += 3);
	map.TextDraw("3. Sword  ", x+5, y += 3);
	map.TextDraw("4. Wand  ", x+5, y += 3);
	map.TextDraw("5. Hammer  ", x+5, y += 3);
	map.TextDraw("������  ", x + 5, y += 3);
}
void Shop::UsingShop(Player* player, int list)
{
	PtrWeapon(list);
	Weapon SetItem[5];
	int select = map.MenuSelectCursor(6, 3, 4, 5);
	if (select == Exit)
	{
		return;
	}
	switch (list)//���Ⱑ ����
	{
	case Bow:
		for (int i = 0; i < MaxItemCount; i++)
		{
			SetItem[i] = BowList[i];
		}
		break;
	case Dagger:
		for (int i = 0; i < MaxItemCount; i++)
		{
			SetItem[i] = DaggerList[i];
		}
		break;
	case Sword:
		for (int i = 0; i < MaxItemCount; i++)
		{
			SetItem[i] = SwordList[i];
		}
		break;
	case Wand:
		for (int i = 0; i < MaxItemCount; i++)
		{
			SetItem[i] = WandList[i];
		}
		break;
	case Hammer:
		for (int i = 0; i < MaxItemCount; i++)
		{
			SetItem[i] = HammerList[i];
		}
		break;
	}
	player->getItem(SetItem[select - 1].retName());
	player->setMoney(-SetItem[select - 1].retValue());
}

void Shop::showItem(Player* player)//������ ������ Ȯ�ν����ش�
{
	system("cls");
	SetData();
	ShopMenu();
	switch (map.MenuSelectCursor(6, 3, 7, 8))
	{
	case Bow:
		UsingShop(player, Bow);
		break;
	case Dagger:
		UsingShop(player, Dagger);
		break;
	case Sword:
		UsingShop(player, Sword);
		break;
	case Wand:
		UsingShop(player, Wand);
		break;
	case Hammer:
		UsingShop(player, Hammer);
		break;
	case Exit:
		return;
	}
	
}

