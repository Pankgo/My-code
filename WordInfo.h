#include "Master.h"

class WordInfo
{
	int word_x = 0;
	int word_y = 1;//y좌표는 항상 고정
	string wordName;
	int wordskill = 0;
	
public:
	void setWord(string name,int limitx)
	{
		wordName = name;
		word_x = limitx;
	}
	bool Checkword(string name)
	{
		if (wordName == name)
		{
			return true;
		}
		return false;
	}
	int GetWordSkill()
	{
		return wordskill;
	}
	void SetwordSkill(int skill)
	{
		wordskill = skill;
	}
	void setWord_y()
	{
		word_y += 1;
	}

	int getWord_x()
	{
		return word_x;
	}
	int getWord_y()
	{
		return word_y;
	}
	string getWord()
	{
		return wordName;
	}



};