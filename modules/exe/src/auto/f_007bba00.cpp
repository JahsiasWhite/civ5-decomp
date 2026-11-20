#define WIN32_LEAN_AND_MEAN
#include <windows.h>

// src: GUESS (confidence: low) [0x007bba00]
struct Unk_007bba00
{
    virtual void V0();
    virtual void V1();
    // src: GUESS (confidence: low)
    virtual void V2();

    char m_pad04[0x10];  // +0x04
    HDC m_hDC;           // +0x14

    // src: GUESS (confidence: high) [0x007bba00]
    HRESULT InitDC_007bba00();
};

// src: GUESS (confidence: high) [0x007bba00]
HRESULT Unk_007bba00::InitDC_007bba00()
{
    m_hDC = CreateCompatibleDC(0);
    if (!m_hDC)
    {
        V2();
        return E_FAIL;
    }
    return S_OK;
}
