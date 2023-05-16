#include "NewsManager.h"

void NewsManager::Menu()
{
	std::cout << "===Atents News===" << std::endl;
	std::cout << "1. 고객등록" << std::endl;
	std::cout << "2. News전송" << std::endl;
	std::cout << "3. News업데이트=" << std::endl;
	std::cout << "4. News시청" << std::endl;
	std::cout << "선택 : ";
}

void NewsManager::PlayNews()
{

	while (1)
	{
		Menu();

		int select;
		std::cin >> select;
		switch (select)
		{
		case 1:
			NEWS->AddOb();
			break;
		case 2:
			NEWS->UpdateNews();
			break;
		case 3:
			NEWS->UpdateOb();
			break;
		case 4:
			NEWS->ObInfoPrint();
			break;

		}
	}


}

