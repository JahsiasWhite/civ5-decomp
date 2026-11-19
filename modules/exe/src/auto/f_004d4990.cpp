// Passes the window's client rectangle to the renderer (virtual slot 6).

#include <windows.h>

// src: GUESS (confidence: low)
class Renderer_00411d60
{
public:
    virtual void __stdcall v00();
    virtual void __stdcall v01();
    virtual void __stdcall v02();
    virtual void __stdcall v03();
    virtual void __stdcall v04();
    virtual void __stdcall v05();
    // src: GUESS (confidence: low)
    virtual void __stdcall Resize(int flags, const RECT* clientRect);
};

// src: GUESS (confidence: low)
class View_00411d60
{
public:
    // src: GUESS (confidence: low) [0x00411d60]
    void OnResize(HWND window);

    char m_pad0[0x28];
    // src: GUESS (confidence: low)
    Renderer_00411d60* m_renderer;
};

void View_00411d60::OnResize(HWND window)
{
    if (m_renderer)
    {
        RECT clientRect;
        GetClientRect(window, &clientRect);
        m_renderer->Resize(0, &clientRect);
    }
}
