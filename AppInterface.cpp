#include "stdafx.h"

using namespace BaseInterface;


ConsoleInterface::ConsoleInterface()
{
	//	system("mode con cols=80 lines=50 ");
	//	system("color F0");
	std::vector<std::string>Text;
	Text.push_back("2016 Scyga");
	DecoratorConsole MainMenu(DecoratorConsole(new Menu(Menu::main)));
	MainMenu.Show();
	DecoratorConsole SimpleTexBox(DecoratorConsole(new TextArea(Text)));
	SimpleTexBox.Show();
	//MainMenu.~ITextControl();
}
ConsoleInterface::ConsoleInterface(int i)
{
	system("mode con cols=80 lines=50 ");
	system("color F0");
}

ConsoleInterface::~ConsoleInterface()
{

}


template <typename T>
static void ConsoleInterface::ShowMessage(T msg)
{
	T temp;
	temp = msg;
	std::cout << temp << "\n";
};
template <typename T>
static void ConsoleInterface::ShowMessage(std::vector<T> MessageVector)
{
	for each (T temp in MessageVector)
	{
		std::cout << "<Vector>" << temp << "</Vector>" << "\n";
	}

};


//char ConsoleInterface::Get_Input_Keyboard()
//{
//	char c;
//	std::cin >> c;
//	return c;
//}
COORD ConsoleInterface::SetCursor(int x, int y)
{

	ControlPos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), ControlPos);
	return ControlPos;
}
void ConsoleInterface::DrawRectangle(int w, int h)
{

	Rectangle(this->hdc, ControlPos.X, ControlPos.Y, w, h);
}


 void ConsoleInterface::DrawLine(int x, int y)
{
	MoveToEx(this->hdc, ControlPos.X, ControlPos.Y, NULL);
	LineTo(this->hdc, x, y);
}
 

void ConsoleInterface::DrawGrid(Graphcoord &GH, int scale)
{
	scale = (scale > 1) ? scale : 2;
	for (int i = 0; i < GH.length; i += scale)
	{
		MoveToEx(this->hdc, GH.centerx, GH.centery + i, NULL);
		LineTo(this->hdc, 0, GH.centery + i);
		MoveToEx(this->hdc, GH.centerx, GH.centery - i, NULL);
		LineTo(this->hdc, 0, GH.centery - i);
		MoveToEx(this->hdc, GH.centerx, GH.centery + i, NULL);
		LineTo(this->hdc, 1000, GH.centery + i);
		MoveToEx(this->hdc, GH.centerx, GH.centery - i, NULL);
		LineTo(this->hdc, 1000, GH.centery - i);
		MoveToEx(this->hdc, GH.centerx + i, GH.centery, NULL);
		LineTo(this->hdc, GH.centerx + i, 0);
		MoveToEx(this->hdc, GH.centerx - i, GH.centery, NULL);
		LineTo(this->hdc, GH.centerx - i, 0);
		MoveToEx(this->hdc, GH.centerx + i, GH.centery, NULL);
		LineTo(this->hdc, GH.centerx + i, 1000);
		MoveToEx(this->hdc, GH.centerx - i, GH.centery, NULL);
		LineTo(this->hdc, GH.centerx - i, 1000);
	}
	//ReleaseDC(this->hWnd, this->hdc);
}


//void ConsoleInterface::DrawFrame(int arrayp)
//{
//	int Map[2][2] = { { 1, 2 }, { 3, 4 } };
//
//	for (int i = 0; i < 2; i++)
//	{
//		for (int j = 0; j < 2; j++)
//		{
//			if (Map[i][j] == 1)
//				std::cout << (char)201;
//			if (Map[i][j] == 2)
//				std::cout << (char)187 << '\n';
//
//			if (Map[i][j] == 3)
//				std::cout << (char)200;
//			if (Map[i][j] == 4)
//				std::cout << (char)188;
//		}
//	
//	}
//	
//}





void DecoratorWindow::Show()
{

}
void DecoratorConsole::Show()
{

	ConsoleInterface::ShowMessage("----------");
	m_component->Show();
	ConsoleInterface::ShowMessage("----------");


}

void ITextControl::Show()
{

	ConsoleInterface::ShowMessage(this->title);
	ConsoleInterface::ShowMessage("___________");
	int i = 1;
	for each (std::string temptitle in Items)
	{
		std::cout << i << ":" << temptitle << "\n";
		i++;
	}

}
void ITextControl::Create()
{


}
void ITextControl::AddItem(std::string item)
{
	Items.push_back(item);
}
TextArea::TextArea(std::vector<std::string> text)
{

	for each (std::string temptitle in text)
	{
		AddItem(temptitle);

	}

}
void TextArea::Show()
{

	for each (std::string temptitle in Items)
	{
		std::cout << temptitle << "\n";

	}

}

void TextArea::Clear()
{

	Items.clear();

}
void Menu::Show()
{
	ConsoleInterface::ShowMessage(this->title);
	ConsoleInterface::ShowMessage("___________");
	int i = 1;
	for each (std::string temptitle in Items)
	{
		std::cout << i << ":" << temptitle << "\n";
		i++;
	}

}
void Menu::Clear()
{

	Items.clear();

}
Menu::Menu(Menu::menutype mt)
{
	switch (mt)
	{
	case Menu::menutype::main:
		SetTitle("Главное меню");
		AddItem("Старт");
		AddItem("Загрузка");
		AddItem("Опции");
		AddItem("Выход");
		//this->Show();
		break;
	case Menu::menutype::options:
		SetTitle("Опции");
		AddItem("Опция1");
		AddItem("Опция2");
		AddItem("Вернутся");
		//this->Show();
		break;
	case Menu::menutype::selectgame:
		SetTitle("Тип игры");
		AddItem("Спринт");
		AddItem("Охота за сокровищами");
		AddItem("Вернутся");
		//this->Show();
		break;
	case Menu::menutype::load:
		SetTitle("Загрузка");
		AddItem("Сохранение1");
		AddItem("Сохранение2");
		AddItem("Вернутся");
		//this->Show();
		break;
	default:
		break;
	}

};
InterfaceType::InterfaceType(int _type)
{

	type = _type;

};


void InterfaceType::AddItem(ITextControl itc)
{
	switch (this->type)
	{

	case 0:ConsoleItems.push_back(GetCOBject(itc));
		break;
	case 1:WindowItems.push_back(GetWOBject(itc));
		break;

	}

}

DecoratorConsole InterfaceType::GetCOBject(ITextControl tc)
{
	ITextControl* ptc = new ITextControl(tc);
	DecoratorConsole obj = DecoratorConsole(ptc);
	return obj;


}
DecoratorWindow InterfaceType::GetWOBject(ITextControl tc)
{
	ITextControl* ptc = new ITextControl(tc);
	DecoratorWindow obj = DecoratorWindow(ptc);
	return obj;
}
