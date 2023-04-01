#include "Login.h"

int main()
{
	std::string consoleTitle = (std::string)skCrypt("Loader name");
	SetConsoleTitleA(consoleTitle.c_str());

	/*
		Optional - check if HWID or IP blacklisted
	if (KeyAuthApp.checkblack()) {
		abort();
	}
	*/
	
	int LoginBool = 1;


	ConnectingStatus();

	if (LoginBool == 1)
	{
		LoginKey();
	}
	else if (LoginBool == 2)
	{
		LoginUserPass();
	}

	Sleep(-1);

}
