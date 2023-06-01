#include "AnglerOwnedState.h"
#include "EntityNames.h"
#include "ConsoleUtils.h"

EnterFishAndFishing* EnterFishAndFishing::Instance()
{
	static EnterFishAndFishing instance;
	return &instance;
}

void EnterFishAndFishing::Enter(Angler* pAngler)
{
	if (pAngler->Location() != Location_Type::fish)
	{
		SetTextColor(FOREGROUND_RED | FOREGROUND_INTENSITY);
		std::cout << GetNameOfEntity(pAngler->ID()) << ":낚시터로 걸어간다" << std::endl;

		pAngler->ChangeLocation(Location_Type::fish);
	}
}

void EnterFishAndFishing::Excute(Angler* pAngler)
{
	if (pAngler->CheckCount() == COUNT_FISHING)
	{
		std::cout << GetNameOfEntity(pAngler->ID()) << "물고기를 잡았다!" << std::endl;
		pAngler->SetFishCarried(1);
		pAngler->CountFishing(-1); // 다시초기화
	}
	else
	{
		pAngler->CountFishing(1);
	}

	
	pAngler->IncreaseHungry();
	pAngler->IncreaseThirsty();
	pAngler->IncreaseFatigue();

	SetTextColor(FOREGROUND_RED | FOREGROUND_INTENSITY);
	std::cout << GetNameOfEntity(pAngler->ID()) << "낚시중..." << std::endl;

	// 생선을 다잡게 되면
	if (pAngler->FishCarried() == MAX_FISH)
	{
		// 상점에 판매.
		pAngler->ChangeState(VisitShopAndBuyOrSell::Instance());
	}
	else
	{
		if (pAngler->Thirsty())	// 목이 마르면,
		{
			// 목마름 해소를 위해 행동.
			pAngler->ChangeState(QuenchThirst::Instance());
		}
		if (pAngler->Hungry())
		{
			// 목마름 해소를 위해 행동.
			pAngler ->ChangeState(QuenchHungry::Instance());
		}
		if (pAngler->Fatigued())
		{
			std::cout << GetNameOfEntity(pAngler->ID()) << "피곤하니 집으로가자..." << std::endl;
			pAngler->ChangeState(GoHomeAndSleepTilRested::Instance());
		}
	}

}

void EnterFishAndFishing::Exit(Angler* pAngler)
{
	SetTextColor(FOREGROUND_RED | FOREGROUND_INTENSITY);
	std::cout << GetNameOfEntity(pAngler->ID()) << ":물고기 " << pAngler->FishCarried() << "개를 잡았다!" << std::endl;
}
// -------------------------------------------------------------
// VisitShopAndBuyOrSell------------------------------------

VisitShopAndBuyOrSell* VisitShopAndBuyOrSell::Instance()
{
	static VisitShopAndBuyOrSell instance;
	return &instance;
}

void VisitShopAndBuyOrSell::Enter(Angler* pAngler)
{
	if (pAngler->Location() != Location_Type::shop)
	{
		SetTextColor(FOREGROUND_RED | FOREGROUND_INTENSITY);
		std::cout << GetNameOfEntity(pAngler->ID()) << ":상점으로 이동" << std::endl;

		pAngler->ChangeLocation(Location_Type::shop);
	}
}

void VisitShopAndBuyOrSell::Excute(Angler* pAngler)
{
	if (pAngler->FishCarried() >= MAX_FISH)
	{
		// 물고기 소지량이 다찼을 경우
		SetTextColor(FOREGROUND_RED | FOREGROUND_INTENSITY);
		pAngler->SetFishCarried(-5);
		pAngler->SetMoney(5);
		std::cout << GetNameOfEntity(pAngler->ID()) << ":\"물고기를 판매하였습니다.\"" << std::endl;
		std::cout << GetNameOfEntity(pAngler->ID()) << ": 현재 돈:" << pAngler->MoneyFull() << std::endl << std::endl;
		if (pAngler->MoneyFull() >= MAX_MONEY)
		{
			pAngler->ChangeState(VisitBankAndDepositGold::Instance());
		}
		else
		{
			// 
			pAngler->ChangeState(EnterFishAndFishing::Instance());
		}
	}
	else
	{
		// 물이 부족하여 물을 사러 왔다.
		if (pAngler->FishCarried() == 0) // 배고픔을 돈으로 해결
		{
			std::cout << GetNameOfEntity(pAngler->ID()) << ":\"돈을 소비하여 빵을 사서 배고픔 해결.\"" << std::endl;
			pAngler->SetMoney(-1);
			pAngler->EatFish();
		}
		else if (pAngler->MoneyFull() <= 0)
		{
			std::cout << GetNameOfEntity(pAngler->ID()) << ":\"돈이 부족하여 물고리를 판매하여 물병을 얻었습니다.\"" << std::endl;
			pAngler->SetFishCarried(-1);
			pAngler->SetBottle(2);
		}
		else
		{
			std::cout << GetNameOfEntity(pAngler->ID()) << ":\"돈을 소비하여 물병을 얻었습니다.\"" << std::endl;
			pAngler->SetMoney(-1);
			pAngler->SetBottle(2);
		}
		pAngler->ChangeState(EnterFishAndFishing::Instance()); // 물병 획득후 또는 배고픔을 해결 한 뒤 낚시터로 이동
	}
}
void VisitShopAndBuyOrSell::Exit(Angler* pAngler)
{
	SetTextColor(FOREGROUND_RED | FOREGROUND_INTENSITY);
	std::cout << GetNameOfEntity(pAngler->ID()) << "상점을 나선다." << std::endl;
}

// VisitBankAndDepositGold ------------------------------------

VisitBankAndDepositGold* VisitBankAndDepositGold::Instance()
{
	static VisitBankAndDepositGold instance;
	return &instance;
}

void VisitBankAndDepositGold::Enter(Angler* pAngler)
{
	if (pAngler->Location() != Location_Type::bank)
	{
		SetTextColor(FOREGROUND_RED | FOREGROUND_INTENSITY);
		std::cout << GetNameOfEntity(pAngler->ID()) << ":은행으로 이동" << std::endl;

		pAngler->ChangeLocation(Location_Type::bank);
	}
}

void VisitBankAndDepositGold::Excute(Angler* pAngler)
{
	pAngler->AddToWealth(pAngler->MoneyFull());

	pAngler->SetMoney(MAX_MONEY);

	SetTextColor(FOREGROUND_RED | FOREGROUND_INTENSITY);
	std::cout << GetNameOfEntity(pAngler->ID()) << ":돈 저금\n\n현재 잔금:" << pAngler->Wealth() << std::endl << std::endl;

	// 저축 금액을 확인,
	if (pAngler->Wealth() >= COMFORT_LEVEL)
	{
		// 만족할 만큼 돈을 모았다.
		SetTextColor(FOREGROUND_RED | FOREGROUND_INTENSITY);
		std::cout << GetNameOfEntity(pAngler->ID()) << ":\"우와! 이제 나는 부자다. 집에 있는 아내에게로 돌아가지.\"" << std::endl;

		pAngler->ChangeState(GoHomeAndSleepTilRested::Instance());
	}
	else
	{
		// 만족할만한 돈이 아니어서 낚시터로 이동.
		pAngler->ChangeState(EnterFishAndFishing::Instance());
	}
}

void VisitBankAndDepositGold::Exit(Angler* pAngler)
{
	SetTextColor(FOREGROUND_RED | FOREGROUND_INTENSITY);
	std::cout << GetNameOfEntity(pAngler->ID()) << ":은행을 떠난다" << std::endl;
}
// -------------------------------------------------------------

// GoHomeAndSleepTilRested -------------------------------------

GoHomeAndSleepTilRested* GoHomeAndSleepTilRested::Instance()
{
	static GoHomeAndSleepTilRested instance;
	return &instance;
}

void GoHomeAndSleepTilRested::Enter(Angler* pAngler)
{
	if (pAngler->Location() != Location_Type::shack)
	{
		SetTextColor(FOREGROUND_RED | FOREGROUND_INTENSITY);
		std::cout << GetNameOfEntity(pAngler->ID()) << ":집으로 들어간다" << std::endl;

		pAngler->ChangeLocation(Location_Type::shack);
	}
}

void GoHomeAndSleepTilRested::Excute(Angler* pAngler)
{
	// 피로도를 확인.
	if (pAngler->GetFatigued()==0)
	{
		// 피로가 다 필리면 다시 금을 캐러같다.
		SetTextColor(FOREGROUND_RED | FOREGROUND_INTENSITY);
		std::cout << GetNameOfEntity(pAngler->ID()) << ":\"낮잠을 늘어지게 잤네! 낚시터로 빨리가자.\"" << std::endl;

		pAngler->ChangeState(EnterFishAndFishing::Instance());
	}
	else
	{
		// 피곤하니 잠을 잔다.
		pAngler->DecreaseFatigue();

		SetTextColor(FOREGROUND_RED | FOREGROUND_INTENSITY);
		std::cout << GetNameOfEntity(pAngler->ID()) << ":...zZ" << std::endl;
	}
}

void GoHomeAndSleepTilRested::Exit(Angler* pAngler)
{
	SetTextColor(FOREGROUND_RED | FOREGROUND_INTENSITY);
	std::cout << GetNameOfEntity(pAngler->ID()) << ":집을 떠난다" << std::endl;
}
// -------------------------------------------------------------

// QuenchThirst ------------------------------------------------
QuenchThirst* QuenchThirst::Instance()
{
	static QuenchThirst instance;
	return &instance;
}

void QuenchThirst::Enter(Angler* pAngler)
{
	std::cout << GetNameOfEntity(pAngler->ID()) << "가방에서 물을 꺼내자" << std::endl;
}

void QuenchThirst::Excute(Angler* pAngler)
{
	// 갈증이 있다면,
	if (pAngler->Thirsty())
	{
		if (pAngler->Bottle() == 0)
		{
			std::cout << GetNameOfEntity(pAngler->ID()) << "이런! 물이없네 ..." << std::endl;
			pAngler->ChangeState(VisitShopAndBuyOrSell::Instance());
		}
		else
		{
			std::cout << GetNameOfEntity(pAngler->ID()) << "물을 마시니 시원하군!" << std::endl;
			pAngler->DrinkWater();
			pAngler->ChangeState(EnterFishAndFishing::Instance());
		}
		
		
	}
	else
	{
		SetTextColor(FOREGROUND_RED | FOREGROUND_INTENSITY);
		std::cout << "\nError!\nError!!\nError!!!" << std::endl;
	}
}
void QuenchThirst::Exit(Angler* pAngler)
{
	SetTextColor(FOREGROUND_RED | FOREGROUND_INTENSITY);
	if (pAngler->Thirsty())
	{
		std::cout << GetNameOfEntity(pAngler->ID()) << " 상점에가자! " << std::endl;
	}
	else
	{
		std::cout << GetNameOfEntity(pAngler->ID()) << "갈증을 해결했으니 다시 낚시를 하자" << std::endl;
	}
}
// ----------------------------------------------------------

// QuenchHungry ---------------------------------------------

QuenchHungry* QuenchHungry::Instance()
{
	static QuenchHungry instance;
	return &instance;
}

void QuenchHungry::Enter(Angler* pAngler)
{
	std::cout << GetNameOfEntity(pAngler->ID()) << "잡은 물고기을 꺼내자" << std::endl;
}

void QuenchHungry::Excute(Angler* pAngler)
{
	if (pAngler->FishCarried() == 0)
	{
		std::cout << GetNameOfEntity(pAngler->ID()) << " 이런 물고기가 없군! " << std::endl;
		pAngler->ChangeState(VisitShopAndBuyOrSell::Instance());
	}
	else
	{
		pAngler->EatFish();
		std::cout << GetNameOfEntity(pAngler->ID()) << " 야무지게 먹어야지! " << std::endl;
		pAngler->ChangeState(EnterFishAndFishing::Instance());
	}
}
void QuenchHungry::Exit(Angler* pAngler)
{
	SetTextColor(FOREGROUND_RED | FOREGROUND_INTENSITY);
	if (pAngler->Hungry())
	{
		std::cout << GetNameOfEntity(pAngler->ID()) << " 상점에가자! " << std::endl;
	}
	else
	{
		std::cout << GetNameOfEntity(pAngler->ID()) << "배고픔을 해결했으니 다시 낚시를 하자" << std::endl;
	}
	
}