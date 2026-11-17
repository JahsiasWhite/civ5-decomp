// c5d-model: Gemini 4 Hydrogen
class Host_0069cd10 {
public:
    char pad[0x20c];
    int m_arr[0x40];
    // src: GUESS (confidence: high) [0x0069cd10]
    int __thiscall GetVal(unsigned int idx) const;
};

int Host_0069cd10::GetVal(unsigned int idx) const {
    if (idx <= 0x3f) {
        return m_arr[idx];
    }
    return 0;
}
