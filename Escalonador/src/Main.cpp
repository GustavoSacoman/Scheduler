#include <Windows.h>
#include <windowsx.h>
#include "../include/Window.h"
#include "../include/Winproc.h"
#include <stdexcept>


int APIENTRY WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nCmdShow)
 {

	int windowStyle			= WS_SYSMENU| WS_OVERLAPPED;

	Window* w				= new Window(960,
		450,
		L"Teste Window",
		windowStyle,
		hInstance);

	WNDPROC win				=  WinProcMain;


	w->CreatingWindowClass(L"WindowClass", CS_HREDRAW | CS_VREDRAW, win);
	w->windowCreate(L"WindowClass");
	w->showWindow(nCmdShow);
	absorveMain(w->getHwnd());



	MSG msg{};
	while (GetMessage(&msg, NULL, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return int(msg.wParam);
	
}






