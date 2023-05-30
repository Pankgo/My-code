#pragma once
#include "Angler.h"


class EnterFishAndFishing : public State // 낚시
{
private:
	EnterFishAndFishing() {}
	EnterFishAndFishing(const EnterFishAndFishing&);
	EnterFishAndFishing& operator=(const EnterFishAndFishing&);

public:
	static EnterFishAndFishing* Instance();

	virtual void Enter(Angler*);
	virtual void Excute(Angler*);
	virtual void Exit(Angler*);
};

class VisitShopAndBuyOrSell : public State // 상점에서 물고기 판매 or 물 구매
{
	VisitShopAndBuyOrSell(){}
	VisitShopAndBuyOrSell(const VisitShopAndBuyOrSell&);
	VisitShopAndBuyOrSell& operator =(const VisitShopAndBuyOrSell&);

public :
	static VisitShopAndBuyOrSell* Instance();

	virtual void Enter(Angler*);
	virtual void Excute(Angler*);
	virtual void Exit(Angler*);
};

class VisitBankAndDepositGold : public State //돈 저장
{
private:
	VisitBankAndDepositGold() {}
	VisitBankAndDepositGold(const VisitBankAndDepositGold&);
	VisitBankAndDepositGold& operator=(const VisitBankAndDepositGold&);

public:
	static VisitBankAndDepositGold* Instance();

	virtual void Enter(Angler*);
	virtual void Excute(Angler*);
	virtual void Exit(Angler*);
};

class GoHomeAndSleepTilRested : public State // 숙면
{
private:
	GoHomeAndSleepTilRested() {}
	GoHomeAndSleepTilRested(const GoHomeAndSleepTilRested&);
	GoHomeAndSleepTilRested& operator=(const GoHomeAndSleepTilRested&);

public:
	static GoHomeAndSleepTilRested* Instance();

	virtual void Enter(Angler*);
	virtual void Excute(Angler*);
	virtual void Exit(Angler*);
};

class QuenchThirst : public State // 갈소 해결
{
private:
	QuenchThirst() {}
	QuenchThirst(const QuenchThirst&);
	QuenchThirst& operator=(const QuenchThirst&);

public:
	static QuenchThirst* Instance();

	virtual void Enter(Angler*);
	virtual void Excute(Angler*);
	virtual void Exit(Angler*);
};

class QuenchHungry : public State // 배고픔해결
{
private:
	QuenchHungry() {}
	QuenchHungry(const QuenchHungry&);
	QuenchHungry& operator=(const QuenchHungry&);

public:
	static QuenchHungry* Instance();

	virtual void Enter(Angler*);
	virtual void Excute(Angler*);
	virtual void Exit(Angler*);
};

