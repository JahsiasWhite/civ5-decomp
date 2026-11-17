// c5d-model: Gemini 4 Hydrogen
class Host_00427d80 {
public:
    char pad0[0x24];
    float m_val;
    char pad1[0xc1504 - 0x28];
    unsigned char m_flags;
    // src: GUESS (confidence: high) [0x00427d80]
    void __thiscall ClearFlag();
};

void __thiscall Host_00427d80::ClearFlag() {
    if (m_flags & 1) {
        m_val = 0.0f;
        m_flags &= ~1;
    }
}
