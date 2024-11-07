
#include <Windows.h>
#include <windowsx.h>
#include "../include/Window.h"
#include "../include/Winproc.h"
#include <stdexcept>
int WindowWidth{ 960 };
int WindowHeight{ 540 };
bool fullScreen{ false };



int APIENTRY WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nCmdShow)
 {

	WNDCLASS windowClass{ };
	windowClass.style = CS_HREDRAW | CS_VREDRAW;
	windowClass.lpfnWndProc = WinProcMain;
	windowClass.cbClsExtra = 0;
	windowClass.cbWndExtra = 0;
	windowClass.hInstance = hInstance;
	windowClass.hIcon = LoadIcon(nullptr, IDI_APPLICATION);
	windowClass.hCursor = LoadCursor(nullptr, IDC_ARROW);
	windowClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	windowClass.lpszMenuName = nullptr;
	windowClass.lpszClassName = L"WindowClass";

	if (!RegisterClass(&windowClass))
		throw std::runtime_error("RegisterClass - failed");

	
	WNDCLASS childClass = {};
	childClass.lpfnWndProc = ChildWinProc;
	childClass.hInstance = hInstance;
	childClass.lpszClassName = L"ChildWindowClass";
	childClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	//childClass.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);

	if (!RegisterClass(&childClass))
		return 1;


	int windowStyle = WS_SYSMENU| WS_OVERLAPPED;
	int windowStyle2 = WS_CHILD | WS_VISIBLE | WS_BORDER;
	
	Window* w		= new Window(960,450,L"Teste Window", windowStyle,hInstance);
	
	w->windowCreate();
	w->showWindow(nCmdShow);
	absorveMain(w->getHwnd());



	MSG msg{};
	while (GetMessage(&msg, NULL, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return int(msg.wParam);
	
}






