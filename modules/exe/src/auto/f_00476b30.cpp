extern "C" {
// src: LIB
__declspec(dllimport) long __stdcall InterlockedDecrement(volatile long* Addend);
// src: LIB
__declspec(dllimport) long __stdcall InterlockedCompareExchange(volatile long* Destination, long Exchange, long Comperand);
}

// src: GUESS (confidence: medium) [0x00829c50]
struct LockState_00829c50 {
    // src: GUESS (confidence: low)
    volatile long m_flags;
    // src: GUESS (confidence: low)
    int m_reserved[4];
    // src: GUESS (confidence: low)
    volatile long m_waitCount;

    // src: GUESS (confidence: medium) [0x00829c50]
    void Release(int active);
};

// src: GUESS (confidence: medium) [0x00829c50]
void LockState_00829c50::Release(int active) {
    if (active != 0) {
        InterlockedDecrement(&m_flags);
        InterlockedCompareExchange(&m_flags, 0x10000, 0);
        if ((m_flags & 0x10000) != 0) {
            InterlockedCompareExchange(&m_waitCount, 0, m_waitCount);
            InterlockedCompareExchange(&m_flags, 0, m_flags);
        }
    }
}
