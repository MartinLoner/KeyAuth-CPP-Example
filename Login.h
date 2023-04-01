#include "auth.hpp"
#include "MainMenu.h"
#include <iostream>
#include <tlhelp32.h>
#include <fstream>
#include <filesystem>
#include "skStr.h"
using namespace KeyAuth;

std::string name = skCrypt("").decrypt(); // application name. right above the blurred text aka the secret on the licenses tab among other tabs
std::string ownerid = skCrypt("").decrypt(); // ownerid, found in account settings. click your profile picture on top right of dashboard and then account settings.
std::string secret = skCrypt("").decrypt(); // app secret, the blurred text on licenses tab and other tabs
std::string version = skCrypt("1.0").decrypt(); // leave alone unless you've changed version on website
std::string url = skCrypt("https://keyauth.win/api/1.2/").decrypt(); // change if you're self-hosting

api KeyAuthApp(name, ownerid, secret, version, url);
void LoginUserPass()
{
	std::cout << skCrypt("\n");
	std::cout << skCrypt("   [1] Login\n");
	std::cout << skCrypt("   [2] Register\n");
	std::cout << skCrypt("   Choose option: ");
	int option;
	std::string username;
	std::string password;
	std::string key;

	std::cin >> option;
	switch (option)
	{
	case 1:
		system(skCrypt("cls"));
		std::cout << skCrypt("\n");
		std::cout << skCrypt("   Enter username: ");
		std::cin >> username;
		std::cout << skCrypt("   Enter password: ");
		std::cin >> password;
		KeyAuthApp.login(username, password);
		if (!KeyAuthApp.data.success)
		{
			std::cout << skCrypt("\n Status: ") << KeyAuthApp.data.message;
			Sleep(1500);
			system(skCrypt("cls"));
			LoginUserPass();
		}
		KeyAuthApp.check();
		MenuHeader();
		break;

	case 2:
		system(skCrypt("cls"));
		std::cout << skCrypt("\n");
		std::cout << skCrypt("   Enter username: ");
		std::cin >> username;
		std::cout << skCrypt("   Enter password: ");
		std::cin >> password;
		std::cout << skCrypt("   Enter license: ");
		std::cin >> key;
		KeyAuthApp.regstr(username, password, key);
		if (!KeyAuthApp.data.success)
		{
			std::cout << skCrypt("\n Status: ") << KeyAuthApp.data.message;
			Sleep(1500);
			system(skCrypt("cls"));
			LoginUserPass();
		}
		KeyAuthApp.check();
		MenuHeader();
		break;

	default:
		std::cout << skCrypt("\n\n Status: Failure: Invalid Selection");
		Sleep(3000);
		system(skCrypt("cls"));
		LoginUserPass();
	}
}

void LoginKey()
{
	std::string key;
	std::cout << skCrypt("\n");
	std::cout << skCrypt("   Enter license: ");
	std::cin >> key;
	KeyAuthApp.license(key);
	if (!KeyAuthApp.data.success)
	{
		std::cout << skCrypt("\n Status: ") << KeyAuthApp.data.message;
		Sleep(1500);
		exit(0);
	}
	KeyAuthApp.check();
	MenuHeader();
}

void ConnectingStatus()
{
	std::cout << skCrypt("\n\n Connecting..");
	KeyAuthApp.init();
	system(skCrypt("cls"));
	system(skCrypt("color d"));
}