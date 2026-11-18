// When the object is both enabled and running, sets its request flag under
// its lock.

#include <windows.h>

// src: GUESS (confidence: low)
class Worker_0082a250
{
public:
    // src: GUESS (confidence: low) [0x0082a250]
    void RequestStop();

    int m_00;
    // src: GUESS (confidence: low)
    bool m_enabled;
    char m_pad5[3];
    // src: GUESS (confidence: low)
    bool m_running;
    char m_pad9[3];
    // src: GUESS (confidence: low)
    CRITICAL_SECTION m_lock;
    char m_pad24[0x10];
    // src: GUESS (confidence: low)
    bool m_stopRequested;
};

void Worker_0082a250::RequestStop()
{
    if (m_enabled && m_running)
    {
        EnterCriticalSection(&m_lock);
        m_stopRequested = true;
        LeaveCriticalSection(&m_lock);
    }
}
