#include<iostream>
#include<windows.h>
//#include"Button.h"
//
// Declare Windows Procedure
//
 LRESULT CALLBACK WindowProcedure(HWND, UINT, WPARAM, LPARAM);

 void ChildLogin(HWND hwnd);
//
// Make A Class Name Into a Global  variable
//
LPCWSTR szClassName = L"MyGuiApp";

//
// This is Main Function 
//
int WINAPI WinMain(HINSTANCE hThisInstance,
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
		HBRUSH windowBrush =  CreateSolidBrush(RGB(100,200,200));
		// Use Window's default Color as background of the window
		m_window.hbrBackground = windowBrush;
		// register the window class and if it fils quit the program
		if(!RegisterClassEx(&m_window))
							return 0 ;
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
// this function is called by the Windows Function DispactchMessage()
LRESULT CALLBACK WindowProcedure(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam) {
	//
	// Handle Message 
	//
	switch (message)
	{
	case WM_CREATE:   // this is message when our main window will Create;//let's show our text in that window
		ChildLogin(hwnd);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hwnd, message, wParam, lParam);
		break;
	}

	return 0;

}
void ChildLogin(HWND  hwnd) {
	/// 
	/// UserName Label
	///
	HWND username = CreateWindow(
		// let's create window for show our text which  will be child window for main window
		L"Static", // Text must not be changed
		L"username: ", ///  any Text for display
		WS_VISIBLE | WS_CHILD ,  // We give our text filed to be visable , to be  child window  , and have border  
		20, 30, // pos(x,y) // positions
		90, 20, // (width , height)
		hwnd, // parent window
		NULL,// do not have Menu
		NULL,// don't have Histance
		NULL // Do not have prameters
	);

	//
	// Username Input TextBox
	//
	HWND inputUsername = CreateWindow( // let's create window for show our text which  will be child window for main window
		L"EDIT", // Text must not be changed
		L"", ///  any Text for display
		WS_VISIBLE | WS_CHILD | WS_BORDER,  // We give our text filed to be visable , to be  child window  , and have border  
		150, 30, // pos(x,y) // positions
		130, 20, // (width , height)
		hwnd, // parent window
		NULL,// do not have Menu
		NULL,// don't have Histance
		NULL // Do not have prameters
	);
	/// 
	/// Password Label
	///
	HWND password = CreateWindow(
		// let's create window for show our text which  will be child window for main window
		L"Static", // Text must not be changed
		L"Password: ", ///  any Text for display
		WS_VISIBLE | WS_CHILD,  // We give our text filed to be visable , to be  child window  , and have border  
		20, 60, // pos(x,y) // positions
		90, 20, // (width , height)
		hwnd, // parent window
		NULL,// do not have Menu
		NULL,// don't have Histance
		NULL // Do not have prameters
	);

	//
	// Username Input TextBox
	//
	HWND inputPassword = CreateWindow( // let's create window for show our text which  will be child window for main window
		L"EDIT", // Text must be changed
		L"", ///  any Text for display
		WS_VISIBLE | WS_CHILD | WS_BORDER,  // We give our text filed to be visable , to be  child window  , and have border  
		150, 60, // pos(x,y) // positions
		130, 20, // (width , height)
		hwnd, // parent window
		NULL,// do not have Menu
		NULL,// don't have Histance
		NULL // Do not have prameters
	);
	//
	// Button
	//
	HWND loginButton = CreateWindow(
		L"Button",// button
		L"Log in",
		WS_VISIBLE | WS_CHILD | WS_BORDER,
		150, 100,
		130, 30,
		hwnd,
		NULL,
		NULL,
		NULL
	);
}