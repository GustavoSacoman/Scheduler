#include "../include/CreateObjectWindow.h"
#include <Windows.h>

CreateObjectWindow::CreateObjectWindow(HWND mainHWND, std::wstring text, int objectstyle, int positionX, int positionY, int objectWidth, int objectHeigh)
{
	this->mainHWND = mainHWND;
	this->text = text;
	this->objectstyle = objectstyle;
	this->positionX = positionX;
	this->positionY = positionY;
	this->objectWidth = objectWidth;
	this->objectHeigh = objectHeigh;
	
}

CreateObjectWindow::~CreateObjectWindow()
{
}

void CreateObjectWindow::createButton(const short indentify)
{
	classObject = L"BUTTON";
	CreateWindow(classObject.c_str(), text.c_str(), objectstyle, positionX, positionY, objectWidth, objectHeigh, mainHWND, (HMENU)indentify, (HINSTANCE)GetWindowLongPtr(mainHWND, GWLP_HINSTANCE), NULL);
}

