#pragma once
#include<Windows.h>
#include<string>
namespace apptool
{
	class Button {
	protected:
		HWND hwndBuuton;
	public:
		Button();
		void createButton(_In_ int x, _In_ int y , _In_ int width , _In_ int height, _In_opt_ LPCWSTR lpWindowName, HWND m_hwnd);
		HWND getButtonWindow();
	};
	class Window {
		HWND mainWindow;
	public:
		void initWindow();
		HWND getWindow();
	};




}