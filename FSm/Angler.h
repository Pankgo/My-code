#pragma once
#include "BaseGameEntity.h"
#include "Locations.h"

#define MAX_FISH		5	// 물고기 최대소지량
#define MAX_MONEY			10	// 최대 소지금.
#define MAX_BOTTLE			3	// 최대물병수
#define THIRST_LEVEL		5	// 갈증 한계.
#define TIREDNESS_THRESHOLD	5	// 피로 한계.

class Miner;
class State
{
public:
	virtual ~State() {}

	virtual void Enter(Miner*) abstract;
	virtual void Excute(Miner*) abstract;
	virtual void Exit(Miner*) abstract;
};

class Angler : public BaseGameEntity
{
private:
	State*			m_pCurrState;
	Location_Type	m_Location;
	int				m_nbottle; // 최대 물병수
	int				m_nfish;	// 광부가 광산에서 캔 금덩이의 양.
	int				m_nMoneyInBank;	// 저축 금액.
	int				m_nCurMoney;	//소지금
	int				m_nHungry;		// 배고픔
	int				m_nThirsty;		// 갈증도.
	int				m_nFatigue;		// 피로도.

public:
	Angler(const int& id);
	virtual ~Angler() {}

	void Update() override;
	void ChangeState(State*);

	Location_Type Location() const { return m_Location; }
	void ChangeLocation(const Location_Type& loc_type) { m_Location = loc_type; }

	int FishCarried() const { return m_nfish; } // 물고기 갯수확인
	void SetFishCarried(const int& value) { m_nfish = value; }// 물고기 추가 혹은 감소
	bool PocketsFull() const { return (MAX_MONEY <= m_nCurMoney); } // 소지금 확인

	bool Hungry() const; // 배고픔 확인
	void EatFish() { m_nfish--; m_nThirsty = 0; } // 배고픔해결

	bool Fatigued() const;						// 피로도확인
	void DecreaseFatigue() { m_nFatigue --; }   // 피로도 감소
	void IncreaseFatigue() { m_nFatigue++; }    // 피로도 증가

	int Wealth() const { return m_nMoneyInBank; } // 현재 저축한 돈확인
	void AddToWealth(const int&); // 돈 저축

	bool Thirsty() const; // 목마름 확인
	void DrinkWater() { m_nThirsty = 0 ; m_nbottle -= 1; } // 목마름 해결
};