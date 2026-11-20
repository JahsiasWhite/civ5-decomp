#define WIN32_LEAN_AND_MEAN
#include <windows.h>

// src: GUESS (confidence: low) [0x00465c60]
struct Mutex_00465c60
{
    HANDLE m_hMutex;  // +0x00

    // src: GUESS (confidence: high) [0x00465c60]
    Mutex_00465c60(bool create);
};

// src: GUESS (confidence: high) [0x00465c60]
Mutex_00465c60::Mutex_00465c60(bool create)
    : m_hMutex(0)
{
    if (create)
        m_hMutex = CreateMutexA(0, FALSE, 0);
}
