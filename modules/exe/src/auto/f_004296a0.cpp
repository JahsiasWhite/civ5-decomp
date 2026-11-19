#include "Unk_00b86290.h"

// src: SDK [0x009d6a5c]
extern "C" __declspec(dllimport) int __stdcall WinHttpCloseHandle(void* handle);

WinHttpHandle_00b86290::~WinHttpHandle_00b86290()
{
    WinHttpCloseHandle(m_handle);
    m_handle = 0;
}
