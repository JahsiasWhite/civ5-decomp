// c5d-model: Gemini 4 Hydrogen
extern "C" __declspec(dllimport) int __stdcall QueryPerformanceCounter(void* lpPerformanceCount);

class Timer_0044ffe0 {
public:
    long long m_start;
    float m_elapsed;
    char pad[0x18];
    int m_count;
    // src: GUESS (confidence: high) [0x0044ffe0]
    void __thiscall Reset();
};

void __thiscall Timer_0044ffe0::Reset() {
    QueryPerformanceCounter(&m_start);
    m_elapsed = 0.0f;
    m_count = 0;
}
