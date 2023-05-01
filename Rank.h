#pragma once
#include "GameManager.h"
#include <algorithm>

class _Rank
{
	DrawMap DrawMap;
	vector<PlayerInfo> PlayerRank;
	PlayerInfo playerInfo;
	int map_width = 60, map_height = 30;
public:
	bool static compare_stage(PlayerInfo& A, PlayerInfo& B)//스테이지 비교함수
	{
		if (A < B)
		{
			return true;
		}
		else if (A == B)
		{
			return true;
		}
		return false;
	}
	void setPlayerRank(PlayerInfo player)
	{
		PlayerRank.push_back(player);
	}
	void SortRank() //랭크정렬
	{
		sort(PlayerRank.begin(), PlayerRank.end(), compare_stage);//오름차순으로 정렬후
		reverse(PlayerRank.begin(), PlayerRank.end());// reverse함수를 사용하여 내림차순으로 정렬
	}
	void PrintRank() //랭크 출력
	{
		int y = 0; 
		int start_x =10;
		int start_Rank = 0;
		int select;
		int i = 0;//8명까지만출력

		DrawMap.Drawtext(start_x, 4, "이름",0);
		DrawMap.Drawtext(map_width, 4, "스테이지",0);
		DrawMap.Drawtext(map_width * 2 - 20, 4, "점수",0);
		for (vector<PlayerInfo>::iterator iter = PlayerRank.begin(); i < 8 && iter != PlayerRank.end(); y+=2,i++,iter++)//출력
		{
			DrawMap.Drawtext(start_x-4, 5+ y, to_string(i+1), 0);
			DrawMap.Drawtext(start_x - 3, 5 + y, "등 ", 0);
			DrawMap.Drawtext(start_x, 5 + y, iter->getName(), 0);
			DrawMap.Drawtext(map_width, 5 + y, to_string(iter->Getstage()), 0);
			DrawMap.Drawtext(map_width * 2 - 20, 5 + y, to_string(iter->GetPoint()), 0);
			
			
		}

	}
	void LoadRank() // 랭크데이터파일 불러오기
	{
		ifstream load;
		string name;
		int stage;
		int point;
		load.open("Rank.txt");

		if (load.is_open())
		{
			while (!load.eof())
			{
				load >> name;
				load >> stage;
				load >> point;
				playerInfo.Setname(name);
				playerInfo.Setstage(stage);
				playerInfo.ResetPoint(point);
				setPlayerRank(playerInfo);
			}
		}

		load.close();
		
	}

	void SaveRank() // 랭크데이터 파일로저장
	{
		ofstream save;
		save.open("Rank.txt");
		vector<PlayerInfo>::iterator iter = PlayerRank.begin();

		while (iter != PlayerRank.end())
		{
			save << iter->getName();
			save << " ";
			save << iter->Getstage();
			save << " ";
			save << iter->GetPoint();
			save << "\n";
			iter++;
		}


	}
	vector<PlayerInfo> GetRank()
	{
		return PlayerRank;
	}

};