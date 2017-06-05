// CartoonOnline.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
using namespace BaseInterface;
char c;

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "Russian");
	AppManager& AM = AppManager::getInstance();
	
	
	AM.ShowTitle();

	int select=0;
	//if (BaseInterface::ConsoleInterface:: != NULL)
	while (AM.On)
	{
		std::cin >> c;
			select = AM.SelectMenu(c, select);
		

	}
	system("pause");
	return 0;
}

