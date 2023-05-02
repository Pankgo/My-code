#pragma once
#include"GameManager.h"
#define NO 0

class WordManager
{
	DrawMap DrawMap;
	WordInfo wordInfo;
	int map_width = 60, map_height = 30;
	string wordList[76];//�ܾ� ����
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
	};
	string getWord(int _str)
	{
		return wordList[_str];
	}
	bool setwordY(PlayerInfo *player,vector<WordInfo>*_curwordList)//y��ǥ ��ȯ �� ��� Ȯ��
	{
		for (vector<WordInfo>::iterator iter = _curwordList->begin(); iter < _curwordList->end(); iter++)//���ӿ� ��µǴ� �ܾ�� y��ǥ ��ȭ
		{
			DrawMap.Drawtext(iter->getWord_x(), iter->getWord_y(), "                ",NO);
			iter->setWord_y();
			if (iter->getWord_y() >=  map_height-1)//�ش�ܾ �ʹ����� ����� �Ǹ� ���Ϳ��� ������ ���ÿ� ������ 1����
			{
				_curwordList->erase(iter);
				player->SetLife(-1);
				if (player->getLife() == 0)
				{
					return false;//����� 0�ΰ�� ���з� ����
				}
				DrawMap.Drawtext(5 + player->getLife() * 2, map_height, "  ",NO);
				break;
			}
		}
		return true;//�ƴѰ�� true ����
	}

	void PrintWord(vector<WordInfo>* _curwordList)
	{
		for (vector<WordInfo>::iterator iter = _curwordList->begin(); iter < _curwordList->end(); iter++)//���� ����ִ� ���� ���
		{
			DrawMap.Drawtext(iter->getWord_x(), iter->getWord_y(), iter->getWord(),iter->GetWordSkill());
		}
	}

	void SetNewWord(vector<WordInfo>* _curwordList)//���ο�ܾ�����
	{
		srand(time(NULL));
		int randnum = 0;
		while (1)
		{
			randnum = rand() % 75;// 75���� ������ �ϳ� �������� �̱�(�ߺ������� �ٽ�)
			for (vector<WordInfo>::iterator iter = _curwordList->begin(); iter < _curwordList->end(); iter++)//�˻縦 ���� ���� �ܾ ���� ��� while�� ��Ƽ��
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
		_curwordList->push_back(wordInfo);
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


};