
#include <Windows.h>
#include <windowsx.h>
#include "../include/Window.h"

int WindowWidth{ 960 };
int WindowHeight{ 540 };
bool fullScreen{ false };



int APIENTRY WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nCmdShow)
 {
	int windowStyle = WS_SYSMENU| WS_OVERLAPPED;
	Window* w		= new Window(960,450,L"Teste Window", windowStyle,hInstance);
	
	w->windowCreate();
	w->showWindow(nCmdShow);
	


	MSG msg{};
	while (GetMessage(&msg, NULL, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return int(msg.wParam);
	

	
}






