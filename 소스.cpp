#include "Square.h"


void main()
{
	int avenue;
	int height;
	setSquare Square;
	while (1)
	{
		system("cls");
		std::cout << " ���� �� �Է� : ";
		std::cin >> avenue;
		if (avenue <= 0)
		{
			std::cout << "0���� �۰ų� ������ �ȵ˴ϴ�.";
			system("pause");
			continue;
		}
		std::cout << " ���� �� �Է� : ";
		std::cin >> height;
		if (height <= 0)
		{
			std::cout << "0���� �۰ų� ������ �ȵ˴ϴ�.";
			system("pause");
			continue;
		}
		Square.Set(avenue, height);
		Square.Draw();
		break;
	}

}

