/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//											Hello Everyone, i,m Nikoloz tchiabrishvili				
//													and 
// 						      This is  my Project For Creating  GUI Login and  Registration System	
//										
//																						
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////		 
#include<iostream>
#include<windows.h>
#include "Mwindow.h"


// Declare Windows Procedure
 LRESULT CALLBACK WindowProcedure(HWND, UINT, WPARAM, LPARAM );
 void Login(HWND hwnd);

// Make A Class Name Into a Global  variable
LPCWSTR szClassName = L"MyGuiApp";

											/// main function
int WINAPI WinMain(HINSTANCE hThisInstance, HINSTANCE hPrevInstance, LPSTR lpszArgument, int nCmdShow)	{	
	/// Create main Window
	apptool::Window  window;
	// Initialize Window
	window.initWindow(hThisInstance, szClassName, WindowProcedure);

		// make window visable on screen
	window.show(nCmdShow);
		// run the massage llop , it will run until GetMessage() return  0 ;
		while (GetMessage(&(window.getMessage()), NULL, 0, 0))
		{
			TranslateMessage(&(window.getMessage()));
			DispatchMessage(&(window.getMessage()));
		}

		return (window.getMessage()).wParam;
}
										/// end of main function


// this function is called by the Windows Function DispactchMessage()
LRESULT CALLBACK WindowProcedure(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam) {
	//
	// Handle Message 
	//
	switch (message)
	{
	case WM_CREATE:   // this is message when our main window will Create;//let's show our text in that window
		Login(hwnd);
		break;
	case WM_COMMAND:

	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hwnd, message, wParam, lParam);
		break;
	}

	return 0;

}
void Login(HWND  hwnd) {
		//	 labels
	apptool::label username(20, 30, 90 , 20, L"username: ", hwnd, (WS_VISIBLE | WS_CHILD)) ,
				   password(20, 60,90, 20,L"Password: ",hwnd,(WS_VISIBLE | WS_CHILD));
		//inputs
	apptool::input Username(150, 30,130, 20,hwnd,WS_VISIBLE | WS_CHILD | WS_BORDER) ,
			Password(150 , 60 , 130 , 20 , hwnd, WS_VISIBLE | WS_CHILD | WS_BORDER);
	apptool::Button loginButton;// button
	loginButton.createButton(150, 90, 130, 30, L"Log in", hwnd , (WS_VISIBLE | WS_CHILD | WS_BORDER) , (HMENU)1 );
}