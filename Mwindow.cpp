#include "Mwindow.h"
void apptool::Window::initWindow(HINSTANCE hThisInstance, LPCWSTR szClassName , LRESULT CALLBACK WindowProcedure(HWND, UINT, WPARAM, LPARAM))
{
	m_window.hInstance = hThisInstance;
	m_window.lpszClassName = szClassName;
	m_window.lpfnWndProc = WindowProcedure;// this function is called by windows
	m_window.style = CS_DBLCLKS; // catch double clicks
	m_window.cbSize = sizeof(WNDCLASSEX);

	//
	//Use Default icon and mouse-Pointer;
	//
	m_window.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	m_window.hIconSm = LoadIconW(NULL, IDI_APPLICATION);
	m_window.hCursor = LoadCursor(NULL, IDC_ARROW);
	m_window.lpszMenuName = NULL; // no menu;
	m_window.cbClsExtra = 0;
	m_window.cbWndExtra = 0;
	HBRUSH windowBrush = CreateSolidBrush(RGB(100, 200, 200));
	// Use Window's default Color as background of the window
	m_window.hbrBackground = windowBrush;
	// register the window class and if it fils quit the program
	if (!RegisterClassEx(&m_window))
		return exit(-1);
	hwnd = CreateWindowEx(
		0, // Extanded Possibilites for variantion
		szClassName, // ClassName
		L"Log in ", // App Name
		WS_SYSMENU,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		544,
		275,
		HWND_DESKTOP,
		NULL,
		hThisInstance,
		NULL
	);
	
}

HWND apptool::Window::getWindow()
{
    return hwnd;
}

MSG& apptool::Window::getMessage()
{
	return messages;
}

BOOL __stdcall apptool::Window::show(int nCmdShow)
{
	return ShowWindow(hwnd, nCmdShow);
}


