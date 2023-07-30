#pragma once
#include<Windows.h>
#include<string>
namespace apptool
{
	/// 
	///  Button
	///
	class Button {
	public:
		Button();
		void createButton(_In_ int x, _In_ int y , _In_ int width , _In_ int height, _In_opt_ LPCWSTR lpWindowName, HWND m_hwnd , DWORD style , HMENU menu = NULL);
		HWND getButtonWindow();//it's return button handler
	private:
		HWND hwndBuuton;
	};
	///
	///  Window
	///
	class Window {
	public:
		void initWindow(HINSTANCE hThisInstance, LPCWSTR szClassName, LRESULT CALLBACK WindowProcedure(HWND, UINT, WPARAM, LPARAM));
		HWND getWindow();
		MSG& getMessage();
		BOOL WINAPI show(int  nCmdShow);
	private:
		HWND hwnd;// handler
		MSG messages; //Here Messages to The applicationare saved
		WNDCLASSEX m_window; // Data Strcuture for Window Class 
	};
	/// 
	///  Label
	/// 
	class label {
	public:
		label(_In_ int x, _In_ int y, _In_ int width, _In_ int height, _In_opt_ LPCWSTR lpWindowName, HWND m_hwnd, DWORD style);
		~label();

	private:
		HWND m_label;
	};
	///
	/// Input
	///
	class input {
	public:

		input(_In_ int x, _In_ int y, _In_ int width, _In_ int height,HWND m_hwnd, DWORD style);
			
	private:
		HWND m_input;
	};


}