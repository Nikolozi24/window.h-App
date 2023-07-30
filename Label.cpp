#include "Mwindow.h"
apptool::label::label(int x, int y, int width, int height, LPCWSTR lpWindowName, HWND m_hwnd, DWORD style, int menu)
{
    m_label = CreateWindow(
        L"STATIC",  // Predefined class; Unicode assumed 
        lpWindowName,      // label static text 
        style,  // Styles 
        x,         // x position 
        y,         // y position 
        width,        // label width
        height,        // labelheight
        m_hwnd,     // Parent window
        (HMENU)menu,       // No menu.
        NULL,
        NULL
    );
}
apptool::label::label() {}

apptool::label::~label(){}
