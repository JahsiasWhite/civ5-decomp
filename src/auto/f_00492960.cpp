// c5d-model: Gemini 4 Hydrogen
class Host_00492960 {
public:
    char pad[0x1cc];
    unsigned char m_bytes[0x40];
    // src: GUESS (confidence: high) [0x00492960]
    unsigned char __thiscall GetByte(unsigned int idx) const;
};

unsigned char Host_00492960::GetByte(unsigned int idx) const {
    if (idx <= 0x3f) {
        return m_bytes[idx];
    }
    return 0;
}
