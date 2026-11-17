// c5d-model: Gemini 4 Hydrogen
class Host_009b2b50 {
public:
    int m_pad0;
    int m_count;
    int** m_ptrs;
    // src: GUESS (confidence: high) [0x009b2b50]
    void __thiscall ClearAll();
};

void __thiscall Host_009b2b50::ClearAll() {
    for (int i = 0; i < m_count; ++i) {
        *m_ptrs[i] = 0;
    }
}
