// c5d-model: Gemini 3.8 Flash
class Host_004739c0 {
public:
    char pad[0x54];
    int m_arr[3];
    // src: GUESS (confidence: high) [0x004739c0]
    int __thiscall GetVal(unsigned int idx) const;
};

int Host_004739c0::GetVal(unsigned int idx) const {
    if (idx <= 2) {
        return m_arr[idx];
    }
    return m_arr[0];
}
