#pragma once
#include "Master.h"
#include "SubJect.h"

#define NEWS News::get_instance()

class NewsManager
{
	void Menu();
public :
	void PlayNews();
};