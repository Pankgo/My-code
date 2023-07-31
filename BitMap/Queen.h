#include "pieces.h"
#pragma once


class Queen : public _Chess
{
public:
	Queen() {};
	void SetMove(Tiles tiles[64], std::vector<_Chess*>pieces) override
	{
		
	}
};