#pragma once
#include <fstream>
#include <skStr.h>

void MenuHeader()
{
	system(skCrypt("cls"));
	system(skCrypt("color 5"));
	std::cout << skCrypt("\n");
	//application code goes below.
	std::cout << skCrypt("   Waiting For Game...\n");
}