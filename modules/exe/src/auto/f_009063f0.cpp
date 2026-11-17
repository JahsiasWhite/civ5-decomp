// c5d-model: Gemini 4 Hydrogen
extern "C" {
    __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long* Addend);
}

// src: GUESS (confidence: high)
class Host_009063f0 {
public:
    void IncrementNonZero();
    char m_pad[0xa00];
    volatile long m_counter;
};

// src: GUESS (confidence: high) [0x009063f0]
void Host_009063f0::IncrementNonZero() {
    if (InterlockedIncrement(&m_counter) == 0) {
        InterlockedIncrement(&m_counter);
    }
}
