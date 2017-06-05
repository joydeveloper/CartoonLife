#include "stdafx.h"
#include "AppManager.h"


int AppManager::SubSystemOptionGet(int value)
{
	return options.apptype;
}


void AppManager::SubSystemOptionSet(Data::AppType at)
{
	options.apptype = at;

}


void AppManager::ShowTitle()
{



	BaseInterface::ConsoleInterface::ShowMessage("     _____           _                      _ _  __     ");
	BaseInterface::ConsoleInterface::ShowMessage("    / ____|         | |                    | (_)/ _|    ");
	BaseInterface::ConsoleInterface::ShowMessage("   | |     __ _ _ __| |_ ___   ___  _ __   | |_| |_ ___ ");
	BaseInterface::ConsoleInterface::ShowMessage("   | |    / _` | '__| __/ _ \ / _ \| '_ \  | | |  _/ _ |");
	BaseInterface::ConsoleInterface::ShowMessage("   | |___| (_| | |  | || (_) | (_) | | | | | | | ||  __/");
	BaseInterface::ConsoleInterface::ShowMessage("    \_____\__,_|_|   \__\___/ \___/|_| |_| |_|_|_| \___|");
	switch (options.apptype)
	{
	case 0:BaseInterface::ConsoleInterface();
		AppView = BaseInterface::InterfaceType(0);
		AppView.AddItem(BaseInterface::Menu(BaseInterface::Menu::selectgame));
		AppView.AddItem(BaseInterface::Menu(BaseInterface::Menu::load));
		AppView.AddItem(BaseInterface::Menu(BaseInterface::Menu::options));
		break;
	case 1:BaseInterface::WindowInterface();
	}
	
	On = true;
}
int AppManager::SelectMenu(char select, int lev)
{
	int _select=lev;
	if (lev == 0)
		switch (select)
	{
	case '1':AppView.ConsoleItems[0].Show();
		_select = 1;
		break;
	case '2':AppView.ConsoleItems[1].Show();
		_select = 2;
		break;
	case '3':AppView.ConsoleItems[2].Show();
		_select = 2;
		break;
	default:
		ShowTitle();
		_select = 0;
		break;
	}
	if (lev == 1)
		switch (select)
	{
		case '1':BaseInterface::ConsoleInterface::ShowMessage("Спринт");
		
			GameManager(SprintMode().StartGame(GameMode, options,playerorder));
			this->On = false;
			return 0;
			break;
		case '2':BaseInterface::ConsoleInterface::ShowMessage("Охота за сокровищами");
			this->On = false;
			return 0;
			break;
		default:
			ShowTitle();
			return 0;
			break;
	}
	else if (lev == 2)
	{
		switch (select)
		{
		case '1':BaseInterface::ConsoleInterface::ShowMessage("Загрузить....");
			return 0;
			break;
		default:
			ShowTitle();
			return 0;
			break;
		}

	}
	else if (lev == 3)
	{
		switch (select)
		{
		case '1':BaseInterface::ConsoleInterface::ShowMessage("Опция1");
			return 0;
			break;
		case '2':BaseInterface::ConsoleInterface::ShowMessage("Опция2");
			return 0;
			break;
		default:
			ShowTitle();
			return 0;
			break;
		}

	}
	return _select;
}
char AppManager::GetUserInput()
{
	return 0;
}


int AppManager::CreateGame(int GameType)
{
	return 0;
}


int AppManager::LoadData()
{
	return 0;
}
std::string AppManager::GetUserOptions(int Coption)
{
	return "";
}
void AppManager::Exit()
{

}


