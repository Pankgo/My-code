#include "pieces.h"

class BiShop : public _Chess
{
public:
	void Move(std::vector<Tiles>* tiles, std::vector<std::shared_ptr<_Chess>>pieces) override
	{
		for (auto iter = tiles->begin(); iter < tiles->end(); iter++)
		{
			switch (GetColor())
			{
			case black:

				break;
			default:
				break;
			}
		}
	}

};