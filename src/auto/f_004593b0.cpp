// c5d-model: Gemini 4 Hydrogen
class Host_004593b0 {
public:
    char pad[0x30c];
    int m_arr[0x40];
    // src: GUESS (confidence: high) [0x004593b0]
    int __thiscall GetVal(unsigned int idx) const;
};

int Host_004593b0::GetVal(unsigned int idx) const {
    if (idx <= 0x3f) {
        return m_arr[idx];
    }
    return 0;
}
