#include "Button.h"

apptool::Button::Button(){}

void apptool::Button::createButton(_In_ int x, _In_ int y, _In_ int  width, _In_ int height , _In_opt_ LPCWSTR lpWindowName,  HWND m_hwnd )
{
    // Create Button  
	    hwndBuuton = CreateWindow(
            L"BUTTON",  // Predefined class; Unicode assumed 
            lpWindowName,      // Button text 
            BS_DEFPUSHBUTTON,  // Styles 
            x,         // x position 
            y,         // y position 
            width,        // Button width
            height,        // Button height
            m_hwnd ,     // Parent window
            NULL,       // No menu.
            (HINSTANCE)GetWindowLongPtr(m_hwnd, GWLP_HINSTANCE),
            NULL
        );      // Pointer not needed.
}

HWND apptool::Button::getButtonWindow()
{
    return this->hwndBuuton;
}

void apptool::Window::initWindow()
{
  
}

HWND apptool::Window::getWindow()
{
    return mainWindow;
}
