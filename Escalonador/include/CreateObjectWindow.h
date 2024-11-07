#pragma once
#include <Windows.h>
#include <string>
class CreateObjectWindow
{
private:
	HWND mainHWND;
	std::wstring classObject;
	std::wstring text;
	int objectstyle;
	int positionX;
	int positionY;
	int objectWidth;
	int objectHeigh;
public:
	CreateObjectWindow(HWND mainHWND, std::wstring text, int objectstyle, int positionX, int positionY, int objectWidth, int objectHeigh);
	
	~CreateObjectWindow();
	void createButton(const short);

};

