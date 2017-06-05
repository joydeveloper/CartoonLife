#pragma once
#include "AppInterface.h"
#include "Data.h"
#include "GameType.h"
#include "GameManager.h"
class AppManager
{
private:
	AppManager() {}
	AppManager(AppManager const&) = delete;
	AppManager& operator= (AppManager const&) = delete;
	int SubSystemOptionGet(int value);
	void SubSystemOptionSet(Data::AppType);
	Data::COption options;
	Data::Mode GameMode;
	Data::PlayerOrder playerorder;
	BaseInterface::InterfaceType AppView;
public:
	static AppManager& getInstance()
	{

		static AppManager  instance;

		return instance;
	}
	bool On;
	void ShowTitle();
	int SelectMenu(char select, int lev);
	char GetUserInput();
	int CreateGame(int GameType);
	int LoadData();

	std::string GetUserOptions(int Coption);
	void Exit();
};

	
	

	


