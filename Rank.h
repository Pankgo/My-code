#pragma once
#include "GameManager.h"
#include <algorithm>

class _Rank
{
	DrawMap DrawMap;
	vector<PlayerInfo> PlayerRank;
	int checkstage =1;
	int map_width = 60;
public:
	bool static compare_stage(PlayerInfo &A, PlayerInfo &B)
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
	bool static compare_point(PlayerInfo &A, PlayerInfo &B)
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
	void SortRank()
	{
		sort(PlayerRank.begin(), PlayerRank.end(), compare_stage);
		sort(PlayerRank.begin(), PlayerRank.end(), compare_point);
	}
	void PrintRank()
	{
		int y = 0;
		for (vector<PlayerInfo>::iterator iter = PlayerRank.begin(); iter < PlayerRank.end(); iter++)//
		{
			DrawMap.Drawtext(map_width, 5 + y, iter->getName());
			y++;
		}
	}
	vector<PlayerInfo> GetRank()
	{
		return PlayerRank;
	}

};