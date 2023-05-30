#include <iostream>
#include "ConsoleUtils.h"
#include "EntityNames.h"
#include "Angler.h"


int main()
{
	/*
	Miner miner(ent_Miner_Bob);

	for (int i = 0; 20 > i; i++)
	{
		miner.Update();

		Sleep(1000);
	}*/

	Angler angler(ent_Elsa);
	while (1)
	{
		angler.Update();
		Sleep(1000);
	}


}