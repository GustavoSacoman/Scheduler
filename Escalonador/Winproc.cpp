#include <Windows.h>
#include <windowsx.h>
#include "../include/CreateObjectWindow.h"
#include "include/Window.h"


HWND mainWindow{};


void absorveMain(HWND T) {
	mainWindow = T;
}
LRESULT CALLBACK WinProcMain(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	CreateObjectWindow* Button = nullptr;
	CreateObjectWindow* Button2 = nullptr;
	Window* newWindow = nullptr;
	switch (uMsg)
	{
	case WM_CREATE:

		Button = new CreateObjectWindow(hwnd,		// mainHWND
			L"Start",							// Text inside button
			WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,	//style
			10,										//positionX
			10,										//positionY
			100,									//width
			50);									//height
		Button->createButton(1);

		Button = new CreateObjectWindow(hwnd,		// mainHWND
			L"Create new process",							// Text inside button
			WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,	//style
			120,										//positionX
			10,										//positionY
			150,									//width
			50);									//height
		Button->createButton(2);
		break;

	case WM_COMMAND:

		if (LOWORD(wParam) == 1) {
			//teste();
			newWindow = new Window(400, 300, L"New Window", WS_OVERLAPPEDWINDOW, (HINSTANCE)GetWindowLongPtr(hwnd, GWLP_HINSTANCE));
			newWindow->windowCreate();
			newWindow->showWindow(SW_SHOWNORMAL);
			MessageBox(NULL, L"This button is working", L"Button", MB_OK | MB_ICONINFORMATION);
			
		}
		break;

	case WM_DESTROY:
		if (hwnd != mainWindow)
			DestroyWindow(hwnd);
		else {
			PostQuitMessage(0);
		}
		return 0;

	}
	return DefWindowProc(hwnd, uMsg, wParam, lParam);
}
