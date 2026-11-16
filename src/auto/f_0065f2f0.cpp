// c5d-model: Gemini 3.8 Flash
class Host_0065f2f0 {
public:
    char pad[0x40];
    int m_flags;
    // src: GUESS (confidence: high) [0x0065f2f0]
    void __thiscall SetFlag(char enable);
};

void Host_0065f2f0::SetFlag(char enable) {
    if (enable) {
        m_flags |= 2;
    } else {
        m_flags &= ~2;
    }
}
