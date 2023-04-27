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
	bool static compare_stage(PlayerInfo& A, PlayerInfo& B)//�������� ���Լ�
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
	void SortRank() //��ũ����
	{
		sort(PlayerRank.begin(), PlayerRank.end(), compare_stage);
	}
	void PrintRank() //��ũ ���
	{
		int y = 0; 
		int start_x =10;
		int start_Rank = 0;
		int select;
		int i = 0;

		DrawMap.Drawtext(start_x, 4, "�̸�",0);
		DrawMap.Drawtext(map_width, 4, "��������",0);
		DrawMap.Drawtext(map_width * 2 - 20, 4, "����",0);
		for (vector<PlayerInfo>::iterator iter = PlayerRank.end()-1; i < 8; iter--)//
		{
			DrawMap.Drawtext(start_x-4, 5+ y, to_string(i+1), 0);
			DrawMap.Drawtext(start_x - 3, 5 + y, "�� ", 0);
			DrawMap.Drawtext(start_x, 5 + y, iter->getName(), 0);
			DrawMap.Drawtext(map_width, 5 + y, to_string(iter->Getstage()), 0);
			DrawMap.Drawtext(map_width * 2 - 20, 5 + y, to_string(iter->GetPoint()), 0);
			y+=2;
			i++;
		}

	}
	void LoadRank() // ��ũ���������� �ҷ�����
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
		//SortRank();
		
	}

	void SaveRank() // ��ũ������ ���Ϸ�����
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