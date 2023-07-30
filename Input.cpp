#include "Mwindow.h"
apptool::input::input(_In_ int x, _In_ int y, _In_ int width, _In_ int height, HWND m_hwnd, DWORD style) {
	m_input = CreateWindow(
		L"EDIT", // Text must be changed
		L"", ///  any Text for display
		style,  // We give our text filed to be visable , to be  child window  , and have border  
		x, y, // pos(x,y) // positions
		width,
		height, // (width , height)
		m_hwnd, // parent window
		NULL,// do not have Menu
		NULL,// don't have Histance
		NULL// Do not have prameters
	);
}