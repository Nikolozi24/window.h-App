/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//											Hello Everyone, i,m Nikoloz tchiabrishvili				
//													and 
// 						      This is  my Project For Creating  GUI Login and  Registration System	
//										
//																						
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////		 
#include<iostream>
#include<atlstr.h>
#include<windows.h>
#include<string>
#include<fstream>

#include "Mwindow.h"

// const  defines
#define IDC_LOGIN_BUTTON (100)
#define IDC_USER_INPUT (200)
#define IDC_PASS_INPUT (300)
#define IDC_USER_LABEL (400)
#define IDC_PASS_LABEL (500)
 // Declare Windows Procedure
 LRESULT CALLBACK WindowProcedure(HWND, UINT, WPARAM, LPARAM );
 std::ofstream ofs("data.txt");
// Make A Class Name Into a Global  variable
LPCWSTR szClassName = L"MyGuiApp";
	//
							//  Login Ccomponents
	//
std::string user_name, pass_word; 

apptool::label username,password;
//inputs
apptool::input Username,Password;
//button
// 
apptool::Button loginButton;
	//
								// end of login components
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
		username = apptool::label(20, 30, 90, 20, L"username: ", hwnd, (WS_VISIBLE | WS_CHILD) ,IDC_USER_LABEL);
		password = apptool::label (20, 60, 90, 20, L"Password: ", hwnd, (WS_VISIBLE | WS_CHILD) , IDC_PASS_LABEL);
		
		Username = apptool::input(150, 30, 130, 20, hwnd, WS_VISIBLE | WS_CHILD | WS_BORDER , IDC_USER_INPUT);
		Password = apptool::input(150, 60, 130, 20, hwnd, WS_VISIBLE | WS_CHILD | WS_BORDER , IDC_PASS_INPUT);
		
		loginButton.createButton(150, 90, 130, 30, L"Log in", hwnd, (WS_VISIBLE | WS_CHILD | WS_BORDER), IDC_LOGIN_BUTTON);
		break;
	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
		case IDC_USER_LABEL:
			//::MessageBox(hwnd, L"user LAbel", L" user LABEL" , MB_YESNO);
			break;
		case IDC_PASS_LABEL:	
		//	::MessageBox(hwnd, L"pass LAbel", L" pass LABEL" , MB_OK);
			break;
		case IDC_USER_INPUT:
			//::MessageBox(hwnd, L"user Input", L" user input", MB_YESNO);
			break;
		case IDC_PASS_INPUT:
			//::MessageBox(hwnd, L"pass input", L" pass input", MB_OK);
			break;
		case IDC_LOGIN_BUTTON:
			 LPWSTR user =NULL, pass = NULL;
			 GetWindowText(Username.getInputWindow(), user, 20);
			 GetWindowText(Password.getInputWindow(), pass, 20);
			char* user_name = CW2A(user);
			char* pass_word = CW2A(pass);
			std::string newUse, newPass;
		
			ofs << user_name;
			ofs << pass_word;
			
			::MessageBox(hwnd, L"Button ", L"BUTTON", MB_OK);
			break;
		}

	case WM_DESTROY:
		//	PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hwnd, message, wParam, lParam);
		break;
	}

	return 0;

}
