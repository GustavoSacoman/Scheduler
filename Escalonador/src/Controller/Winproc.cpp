#include "../include/CreateObjectWindow.h"
#include "../include/Winproc.h"
#include "../../../include/Window.h"
#include "../../../include/ListView.h"


HWND mainWindow{};
Window* newWindow = nullptr;

void absorveMain(HWND T) {
	mainWindow = T;
}
LRESULT CALLBACK WinProcMain(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	CreateObjectWindow* Button = nullptr;
	CreateObjectWindow* Button2 = nullptr;
	
	
	switch (uMsg)
	{
	case WM_CREATE:

		Button = new CreateObjectWindow(hwnd,		// mainHWND
			L"Start",								// Text inside button
			WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,	//style
			10,										//positionX
			10,										//positionY
			100,									//width
			50);									//height
		Button->createButton(1);

		Button = new CreateObjectWindow(hwnd,		// mainHWND
			L"Create new process",					// Text inside button
			WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,	//style
			120,									//positionX
			10,										//positionY
			150,									//width
			50);									//height
		Button->createButton(2);
		break;

	case WM_COMMAND:

		if (LOWORD(wParam) == 1) {
			
			newWindow = new Window(400,
				300,
				L"ListWindow",
				WS_OVERLAPPEDWINDOW,
				(HINSTANCE)GetWindowLongPtr(hwnd, GWLP_HINSTANCE));
			WNDPROC win = testWinproc;
			newWindow->CreatingWindowClass(L"ListWindowClass",
				CS_HREDRAW | CS_VREDRAW,
				win);
			newWindow->windowCreate(L"ListWindowClass");
			newWindow->showWindow(SW_SHOWNORMAL);


			CreateListView(newWindow,hwnd);
				
		

			
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
LRESULT CALLBACK testWinproc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {

	switch (uMsg)
	{
	case WM_DESTROY:
		if (newWindow && newWindow->getHwnd() == hwnd) {
			delete newWindow;
		}
		DestroyWindow(hwnd);
		break;

	}
	return DefWindowProc(hwnd, uMsg, wParam, lParam);
}