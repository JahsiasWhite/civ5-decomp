// c5d-model: Gemini 4 Hydrogen
class Host_008e7b60 {
public:
    char pad0[0x30];
    char* m_base;
    char pad1[2];
    unsigned short m_count;
    // src: GUESS (confidence: high) [0x008e7b60]
    void* __thiscall GetEndAligned();
};

void* __thiscall Host_008e7b60::GetEndAligned() {
    if (m_base) {
        return m_base + ((m_count * 0x34 + 7) & ~7);
    }
    return 0;
}
