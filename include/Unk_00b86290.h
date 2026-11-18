#pragma once
// c5d-vtable: 0x00b86290

// Placeholder: owns a WinHTTP handle and closes it on destruction.
// Rename once the owning type is known.

// src: GUESS (confidence: medium) [0x00b86290]
class WinHttpHandle_00b86290
{
public:
    // src: GUESS (confidence: medium) [0x007e0c10]
    virtual ~WinHttpHandle_00b86290();

    void* m_handle;     // 0x04, an HINTERNET
};
