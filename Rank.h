#pragma once
#include "GameManager.h"
#include <algorithm>

class _Rank
{
	vector<PlayerInfo> PlayerRank;
	int checkstage =1;
	
public:
	bool compare_stage(PlayerInfo A, PlayerInfo B)
	{
		if (A.Getstage() < B.Getstage())
		{
			return A.Getstage() < B.Getstage();
		}
		else
		{
			return A.Getstage() > B.Getstage();
		}
	}
	bool compare_point(PlayerInfo A, PlayerInfo B)
	{
		if (A.GetPoint() < B.GetPoint())
		{
			return A.GetPoint() < B.GetPoint();
		}
		else
		{
			return A.GetPoint() > B.GetPoint();
		}
	}
	void setPlayerRank(PlayerInfo player)
	{
		PlayerRank.push_back(player);
	}
	void PrintRank()
	{
		sort(PlayerRank.begin(), PlayerRank.end(), compare_stage);
		sort(PlayerRank.begin(), PlayerRank.end(), compare_point);
	}
	vector<PlayerInfo> GetRank()
	{
		return PlayerRank;
	}

};