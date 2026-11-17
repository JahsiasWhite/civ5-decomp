// c5d-model: Gemini 4 Hydrogen
class Host_0058c1b0 {
public:
    char pad[0x40];
    unsigned int m_flags;
    // src: GUESS (confidence: high) [0x0058c1b0]
    void __thiscall SetHighBit(bool set);
};

void __thiscall Host_0058c1b0::SetHighBit(bool set) {
    if (set) {
        m_flags |= 0x8000000u;
    } else {
        m_flags &= ~0x8000000u;
    }
}
