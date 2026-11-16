// A thin wrapper around a Win32 critical section. The class's members at
// 0x00813d30-0x00813d60 each pass `this` straight to a kernel32 critical
// section call, so the CRITICAL_SECTION sits at offset 0.
#pragma once
#include <windows.h>

// src: GUESS (confidence: medium)
class FCriticalSection
{
public:
    // src: GUESS (confidence: high) [0x00813d40]
    void Delete();
    // src: GUESS (confidence: high) [0x00813d50]
    void Enter();
    // src: GUESS (confidence: high) [0x00813d60]
    void Leave();

    // src: GUESS (confidence: high)
    CRITICAL_SECTION m_cs;
};
