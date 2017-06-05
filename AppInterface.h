#pragma once
#include <vector>
#include <iostream>
#include <windows.h>
#include <assert.h>
#include <memory>
namespace BaseInterface
{
	template <typename T>
	void ShowMessage(T msg)
	{
		T temp;
		temp = msg;
		std::cout << temp << "\n";
	};
	template <typename T>
	void ShowMessage(T msg,int i)
	{
		T temp;
		temp = msg;
		std::cout << temp;
	};

	template <typename T>
	void ShowMessage(std::vector<T> MessageVector)
	{
		for each (T temp in MessageVector)
		{
			std::cout << "<Vector>" << temp << "</Vector>" << "\n";
		}

	};
	char GetInput_Keyboard()
	{
		char c;
		std::cin >> c;
		return c;

	};

	class ConsoleInterface
	{
	private:
		HWND hWnd = GetConsoleWindow();
		HDC hdc = GetDC(hWnd);
		HPEN hPen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
	    HGDIOBJ hOldPen = (HPEN)SelectObject(hdc, hPen);
	public:

		ConsoleInterface();
		ConsoleInterface(int);
		~ConsoleInterface();

		struct Graphcoord
		{
			int centerx, centery, length;

		} startpoint;
		COORD ControlPos;
		template <typename T>
		static void ShowMessage(T);
		template <typename T>
		static void ShowMessage(std::vector<T>);
		//static char Get_Input_Keyboard();
		 COORD SetCursor(int x, int y);
		 void DrawRectangle(int w, int h);
		void DrawLine(int x, int y);
		 void DrawGrid(Graphcoord &GH, int scale);
		// void DrawFrame(int arrayp);
	};
	class WindowInterface
	{
	private:
	
	public:

		WindowInterface(){};
		~WindowInterface(){};

		
		// void DrawFrame(int arrayp);
	};
	class ITextControl
	{

	public:
		ITextControl(){};
		std::string title = "Control";
		std::string GetTitle() { return title; };
		void SetTitle(std::string _name) { this->title = _name; };
		virtual ~ITextControl(){};
		virtual void Show() ;
		virtual void Create();
		virtual void AddItem(std::string);
		std::vector<std::string>Items;
	};
	class TextArea : public ITextControl
	{
	public:
		TextArea(std::vector<std::string> items);
		virtual void Clear();
		void Show();
	};
	class Menu : public ITextControl
	{
	public:
		enum menutype
		{
			main, options,selectgame,load
		};
		Menu(menutype);
		Menu(){};
		virtual void Clear();
	    void Show();
	};

	class DecoratorWindow :
		public ITextControl
	{
		std::shared_ptr<ITextControl> m_component;
	public:
		DecoratorWindow(ITextControl* control) : m_component(control){};
		virtual void Show();
	};
	class DecoratorConsole:
		public ITextControl
	{
		std::shared_ptr<ITextControl> m_component;

	public:
		DecoratorConsole(ITextControl* control) : m_component(control){};
		DecoratorConsole(Menu* menu) : m_component(menu){};
		virtual void Show();
	};

	class InterfaceType
	{
	public:
		InterfaceType(){};
		InterfaceType(int);
		int type;
		void AddItem(ITextControl);
		virtual ~InterfaceType(){};
		std::vector<DecoratorConsole>ConsoleItems;
		std::vector<DecoratorWindow>WindowItems;
		DecoratorConsole GetCOBject(ITextControl);
		DecoratorWindow GetWOBject(ITextControl);
	};
	//class Console_View :public InterfaceType
	//{
	//public:
	//	Console_View(){};
	//	
	//};
	//class Window_View :public InterfaceType
	//{

	//public:
	//	Window_View(){};
	//	
	//};
}