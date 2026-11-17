// c5d-model: Gemini 4 Hydrogen
class Host_007b1510 {
public:
    char pad[0x1cc];
    unsigned char m_bytes[0x40];
    // src: GUESS (confidence: high) [0x007b1510]
    void __thiscall SetByte(unsigned int idx, unsigned char val);
};

void Host_007b1510::SetByte(unsigned int idx, unsigned char val) {
    if (idx <= 0x3f) {
        m_bytes[idx] = val;
    }
}
