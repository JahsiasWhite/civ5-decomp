// Wraps a Win32 semaphore; a maximum of 0 means 1,000,000.

#include <windows.h>

// src: GUESS (confidence: low)
class Semaphore_00838f10
{
public:
    // src: GUESS (confidence: low) [0x00838f10]
    Semaphore_00838f10(int initialCount, int maxCount);

    // src: GUESS (confidence: low)
    HANDLE m_handle;
};

Semaphore_00838f10::Semaphore_00838f10(int initialCount, int maxCount)
{
    if (maxCount == 0)
        maxCount = 1000000;
    m_handle = CreateSemaphoreA(NULL, initialCount, maxCount, NULL);
}
