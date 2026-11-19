// c5d-cflags: +/Od
// Returns the current time while the timeout hasn't run out, otherwise 0.

// src: GUESS (confidence: low)
extern int g_iGlobal_02de1e20;

// src: GUESS (confidence: low)
struct Timer_00897cf0
{
    char m_pad0[0x11c];
    // src: GUESS (confidence: low)
    unsigned int m_timeout;
    // src: GUESS (confidence: low)
    int m_start;
};

// src: GUESS (confidence: low) [0x00897cf0]
int GetTimeIfActive_00897cf0(Timer_00897cf0* timer)
{
    unsigned int elapsed = g_iGlobal_02de1e20 - timer->m_start;
    if (elapsed >= timer->m_timeout)
        return 0;
    return g_iGlobal_02de1e20;
}
