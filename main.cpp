#include<iostream>
#include<windows.h>
//#include"Button.h"
//
// Declare Windows Procedure
//
extern LRESULT CALLBACK WindowProcedure(HWND, UINT, WPARAM, LPARAM);
//
// Make A Class Name Into a Global  variable
//
LPCWSTR szClassName = L"MyGuiApp";

//
// Yet i Don't Even know what Args or something they Are :<
//
int WINAPI main(HINSTANCE hThisInstance,
		HINSTANCE hPrevInstance,
		LPSTR lpszArgument,
		int nCmdShow
) 

{
	//
	// Create Handle For Window
	//
	HWND hwnd;

	MSG messages; //Here Messages to The applicationare saved

	WNDCLASSEX m_window; // Data Strcuture for Window Class 
	//
	// The WIndow Structure
	// 
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
		// Use Window's default Color as background of the window
		m_window.hbrBackground = (HBRUSH)COLOR_BACKGROUND;
		// register the window class and if it fils quit the program
		if(!RegisterClassEx(&m_window))
							return 0 ;
		hwnd = CreateWindowEx(
			0, // Extanded Possibilites for variantion
			szClassName, // ClassName
			L"My APP ", // App Name
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
		// make window visable on screen
		ShowWindow(hwnd, nCmdShow);
		// run the massage llop , it will run until GetMessage() return  0 ;
		while (GetMessage(&messages , NULL, 0 , 0))
		{
			TranslateMessage(&messages);
			DispatchMessage(&messages);
		}

		return messages.wParam;


		
		
		
	



}