#include "Mwindow.h"

apptool::Button::Button() {}

void apptool::Button::createButton(_In_ int x, _In_ int y, _In_ int  width, _In_ int height, _In_opt_ LPCWSTR lpWindowName, HWND m_hwnd , DWORD style = (WS_VISIBLE | WS_CHILD | WS_BORDER) , HMENU menu)
{
    // Create Button  
    hwndBuuton = CreateWindow(
        L"BUTTON",  // Predefined class; Unicode assumed 
        lpWindowName,      // Button text 
        style,  // Styles 
        x,         // x position 
        y,         // y position 
        width,        // Button width
        height,        // Button height
        m_hwnd,     // Parent window
        menu,       // No menu.
        NULL,
        NULL
    );      // Pointer not needed.
}

HWND apptool::Button::getButtonWindow()
{
    return this->hwndBuuton;
}