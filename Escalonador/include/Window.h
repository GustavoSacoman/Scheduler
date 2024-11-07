#pragma once
#include <string>
#include <Windows.h>
#include <windowsx.h>
class Window
{
private:

	int windowWidth;
	int windowHeight;
	std::wstring windowName;
	int windowStyle;
	HWND hwnd{};
	HINSTANCE hInstance;
	
	

	void initWindow();
	void fullScreamWindow();
public:
	
	Window(int windowWidth, int windowHeight, std::wstring windowName, int windowStyle, HINSTANCE hInstance);
	~Window();
	void windowCreate();
	
	void showWindow(_In_ int nCmdShow);
	HWND getHwnd() const;
	HWND hwndMain();
	
	
};

