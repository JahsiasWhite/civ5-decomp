#pragma once
// c5d-vtable: 0x00b88b8c
#define WIN32_LEAN_AND_MEAN
#include <windows.h>

// Placeholder: owns a critical section at 0x0c and a handle at 0x28, both
// released by its destructor (0x0082a180). Rename once the class is known.

// src: GUESS (confidence: low) [0x00b88b8c]
class Unk_00b88b8c
{
public:
    // src: GUESS (confidence: medium) [0x0082a180]
    virtual ~Unk_00b88b8c();

    int m_unk04[2];
    CRITICAL_SECTION m_lock;    // 0x0c
    int m_unk24;
    HANDLE m_handle;            // 0x28
};
