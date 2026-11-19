extern "C" {
// src: LIB
__declspec(dllimport) long __stdcall InterlockedCompareExchange(volatile long* Destination, long Exchange, long Comperand);
}

// src: GUESS (confidence: medium) [0x00706290]
struct RefTable_00706290 {
    // src: GUESS (confidence: medium)
    volatile long m_lock;
    int m_pad04[0x10];
    // src: GUESS (confidence: medium)
    int m_counts[1];

    // src: GUESS (confidence: medium) [0x00706290]
    int AddRef(int index);
};

// src: GUESS (confidence: medium) [0x00706290]
int RefTable_00706290::AddRef(int index) {
    if (index == 0) {
        return 0;
    }
    while (InterlockedCompareExchange(&m_lock, 1, 0) == 1) {
    }
    int count = ++m_counts[index];
    m_lock = 0;
    return count;
}
