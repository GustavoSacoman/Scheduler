#pragma once
#include <string>
#include <Windows.h>
#include <windowsx.h>

class Window
{
private:
	//Atributtes
	int windowWidth;
	int windowHeight;
	std::wstring windowName;
	int windowStyle;
	HWND hwnd{};
	HINSTANCE hInstance;
	std::wstring className;
	WNDCLASS windowClass{ };

	//Methods private
	void initWindow();
	void fullScreamWindow();
public:
	//Constructor and Destructor
	Window(int windowWidth,
		   int windowHeight,
		   std::wstring windowName,
		   int windowStyle,
		   HINSTANCE hInstance);
	~Window();

	//Getters
	HWND getHwnd() const;
	HWND hwndMain();
	//Public Methods
	void CreatingWindowClass(LPCWSTR,DWORD style, WNDPROC win);
	void windowCreate(std::wstring);
	void showWindow(_In_ int nCmdShow);
	
	
};

