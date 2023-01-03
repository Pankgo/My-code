#include "Square.h"


void main()
{
	int avenue;
	int height;
	setSquare Square;
	while (1)
	{
		system("cls");
		std::cout << " 가로 값 입력 : ";
		std::cin >> avenue;
		if (avenue <= 0)
		{
			std::cout << "0보다 작거나 같으면 안됩니다.";
			system("pause");
			continue;
		}
		std::cout << " 세로 값 입력 : ";
		std::cin >> height;
		if (height <= 0)
		{
			std::cout << "0보다 작거나 같으면 안됩니다.";
			system("pause");
			continue;
		}
		Square.Set(avenue, height);
		Square.Draw();
		break;
	}

}

