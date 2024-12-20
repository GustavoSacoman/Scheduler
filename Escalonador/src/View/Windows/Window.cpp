#include "../include/Window.h"
#include "../include/CreateObjectWindow.h"
#include <stdexcept>
#include "../include/Winproc.h"

struct WindowStyles {
	
};
Window::Window(int windowWidth, int windowHeight,
				std::wstring windowName,int windowStyle,HINSTANCE hInstance):
windowWidth(windowWidth),
windowHeight(windowHeight),
windowName(windowName),
windowStyle(windowStyle),
hInstance(hInstance){}

Window::~Window()
{
}

void Window::CreatingWindowClass(LPCWSTR createName,DWORD style, WNDPROC win)
{

	if (!win) {
		MessageBox(NULL, L"Window procedure is NULL!", L"Error", MB_OK | MB_ICONERROR);
		exit(0);
	}
	if (GetClassInfo(hInstance, createName, &windowClass)) {
		// Class is already registered, no need to register again
		return;
	}

	windowClass.style = style;
	windowClass.lpfnWndProc = win;
	windowClass.cbClsExtra = 0;
	windowClass.cbWndExtra = 0;
	windowClass.hInstance = hInstance;
	windowClass.hIcon = LoadIcon(nullptr, IDI_APPLICATION);
	windowClass.hCursor = LoadCursor(nullptr, IDC_ARROW);
	windowClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	windowClass.lpszMenuName = nullptr;
	windowClass.lpszClassName = createName;

	if (!RegisterClass(&windowClass)) {
		DWORD error = GetLastError();
		MessageBox(NULL, L"RegisterClass failed", L"Error", MB_OK | MB_ICONERROR);
		exit(0);
	}
}

void Window::windowCreate(std::wstring name)
{	
	className = name;
	try {
			initWindow();
			fullScreamWindow();
	}
	catch (const std::runtime_error& e) {
		MessageBox(NULL, std::wstring(e.what(), e.what() + strlen(e.what())).c_str(),
			L"Error", MB_OK | MB_ICONERROR);
	}
}


void Window::initWindow() {

	hwnd = CreateWindowEx(NULL,		// extended style
		className.c_str(),			// class name of window class
		windowName.c_str(),			// window name
		windowStyle,				//window style
		CW_USEDEFAULT,				// x
		CW_USEDEFAULT,				// y
		windowWidth,				// width
		windowHeight,				// height
		NULL,						// parent window
		NULL,						// menu
		hInstance,					// instance
		NULL);						// pass this to WM_CREATE
		
	if (!hwnd)
		throw std::runtime_error("CreateWindow - failed");
}

void Window::fullScreamWindow()
{
	

	RECT winRect = { 0, 0, windowWidth, windowHeight };
	AdjustWindowRectEx(&winRect,
						GetWindowStyle(hwnd),
						GetMenu(hwnd) != NULL,
						GetWindowExStyle(hwnd));
	
	int windowPosX = (GetSystemMetrics(SM_CXSCREEN) - (winRect.right - winRect.left)) / 2;
	int windowPosY = (GetSystemMetrics(SM_CYSCREEN) - (winRect.bottom - winRect.top)) / 2;
	
	MoveWindow(hwnd,
				windowPosX,
				windowPosY,
				winRect.right - winRect.left,
				winRect.bottom - winRect.top,
				TRUE);
	
}

void Window::showWindow(_In_ int nCmdShow)
{
	ShowWindow(hwnd, nCmdShow);
	UpdateWindow(hwnd);
}

HWND Window::getHwnd() const
{
	return hwnd;
}

HWND Window::hwndMain()
{
	return HWND();
}


