// When the worker is enabled and running, clears its paused flag and
// resumes its thread under its lock.

#include <windows.h>

// src: GUESS (confidence: low)
class Worker_0082a320
{
public:
    // src: GUESS (confidence: low) [0x0082a320]
    void Resume();

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
    bool m_paused;
    char m_pad35[3];
    // src: GUESS (confidence: low)
    HANDLE m_thread;
};

void Worker_0082a320::Resume()
{
    if (m_enabled && m_running)
    {
        EnterCriticalSection(&m_lock);
        m_paused = false;
        ResumeThread(m_thread);
        LeaveCriticalSection(&m_lock);
    }
}
