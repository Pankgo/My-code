#pragma once
#include"GameManager.h"
#define NO 0

class WordManager
{
	DrawMap DrawMap;
	WordInfo wordInfo;
	string wordList[76];//�޸���ܾ� ����
	vector<WordInfo> _curwordList;//���� ���ӿ� ��µǴ� �ܾ��Ʈ
	int sequence = 0;
	ifstream load;
	string word;

public :
	WordManager()
	{
		load.open("Word.txt");
		while (!load.eof())//���Ϳ� ����� �ܾ� ����
		{
			getline(load, word);
			wordList[sequence] = word;
			sequence++;
		}
		load.close();
	};
	string getWord(int _str)
	{
		return wordList[_str];
	}
	bool setwordY(PlayerInfo *player,int mapHeight)//y��ǥ ��ȯ �� ��� Ȯ��
	{
		for (vector<WordInfo>::iterator iter = _curwordList.begin(); iter < _curwordList.end(); iter++)//���ӿ� ��µǴ� �ܾ�� y��ǥ ��ȭ
		{
			DrawMap.Drawtext(iter->getWord_x(), iter->getWord_y(), "                ",NO);
			iter->setWord_y();
			if (iter->getWord_y() >=  mapHeight - 1)//�ش�ܾ �ʹ����� ����� �Ǹ� ���Ϳ��� ������ ���ÿ� ������ 1����
			{
				_curwordList.erase(iter);
				player->SetLife(-1);
				if (player->getLife() == 0)
				{
					return false;//����� 0�ΰ�� ���з� ����
				}
				DrawMap.Drawtext(5 + player->getLife() * 2, mapHeight, "  ",NO);
				break;
			}
		}
		return true;//�ƴѰ�� true ����
	}

	void PrintWord()
	{
		for (vector<WordInfo>::iterator iter = _curwordList.begin(); iter < _curwordList.end(); iter++)//���� ����ִ� ���� ���
		{
			DrawMap.Drawtext(iter->getWord_x(), iter->getWord_y(), iter->getWord(),iter->GetWordSkill());
		}
	}

	void SetNewWord()//���ο�ܾ�����
	{
		srand(time(NULL));
		int randnum = 0;
		while (1)
		{
			randnum = rand() % 75;// 75���� ������ �ϳ� �������� �̱�(�ߺ������� �ٽ�)
			for (vector<WordInfo>::iterator iter = _curwordList.begin(); iter < _curwordList.end(); iter++)//�˻縦 ���� ���� �ܾ ���� ��� while�� ��Ƽ��
			{ 
				if (iter->Checkword(wordList[randnum]) == true)
				{
					continue;
				}
			}
			break;
		}
		int x = rand() % 100 + 1;//x��ǥ�� �������� �����ϰ�  y��ǥ�� 1���� �����ϱ⶧���� �ǵ��ʿ� x
		wordInfo.setWord(wordList[randnum], x); 
		wordInfo.SetwordSkill(rand() % 15 + 1);
		_curwordList.push_back(wordInfo);
	}
	bool InputWord(char _word, string *checkWord)
	{
		switch (_word)
		{
		case 13://����
			return true;
		case 8 ://�齺���̽�
			if (checkWord->length() != 0)
			{
				checkWord->pop_back();
			}
			return false;
		default:
			checkWord->push_back(_word);
			return false;
			
		}
	}
	bool Checkword(string checkword)//�Է� �ܾ�� ���� �ܾ �ִ��� Ȯ��
	{
		for (vector<WordInfo>::iterator iter = _curwordList.begin(); iter < _curwordList.end(); iter++)//�˻縦 ���� ���� �ܾ ���� ��� ����
		{
			if (iter->Checkword(checkword) == true)
			{
				DrawMap.Drawtext(iter->getWord_x(), iter->getWord_y(), "                ", 0);
				return(true);
			}
		}
		return false;
	}
	int GetwordSkill(string checkword)//��ų Ȯ�ΰ� ���ÿ� ���Ϳ� �ش�ܾ� ����
	{
		for (vector<WordInfo>::iterator iter = _curwordList.begin(); iter < _curwordList.end(); iter++)//�˻縦 ���� ���� �ܾ ���� ��� ����
		{
			if (iter->Checkword(checkword) == true)
			{
				int skill = iter->GetWordSkill();
				_curwordList.erase(iter);
				return(skill);
			}
		}
	}
	void AllDel ()
	{
		for (vector<WordInfo>::iterator iter = _curwordList.begin(); iter < _curwordList.end(); iter++)
		{
			DrawMap.Drawtext(iter->getWord_x(), iter->getWord_y(), "                ", 0);
		}
		_curwordList.clear();
	}


};