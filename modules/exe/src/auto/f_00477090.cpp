#include <windows.h>

// src: GUESS (confidence: low) [0x0082a1a0]
class UnkWorkerThread_0082a1a0
{
public:
    // Hands the thread its job and resumes it the first time.
    // src: GUESS (confidence: low) [0x0082a1a0]
    int Start(int iJob);

    int m_00;
    // src: GUESS (confidence: low)
    bool m_started;
    char m_pad05[0x24 - 5];
    // src: GUESS (confidence: low)
    int m_job;
    char m_pad28[0x38 - 0x28];
    // src: GUESS (confidence: low)
    HANDLE m_hThread;
};

int UnkWorkerThread_0082a1a0::Start(int iJob)
{
    m_job = iJob;
    if (!m_started)
    {
        m_started = true;
        ResumeThread(m_hThread);
    }
    return 0;
}
