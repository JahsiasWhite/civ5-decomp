#define WIN32_LEAN_AND_MEAN
#include <windows.h>

// src: GUESS (confidence: low)
struct Target_007b95b0
{
    virtual void V0();
    virtual void V1();
    virtual void V2();
    // src: GUESS (confidence: low)
    virtual void V3(int a, int b);
};

// src: GUESS (confidence: high) [0x007b95b0]
HRESULT __stdcall CallV3_007b95b0(Target_007b95b0* p, int a, int b)
{
    if (p)
    {
        p->V3(a, b);
        return S_OK;
    }
    return E_FAIL;
}
