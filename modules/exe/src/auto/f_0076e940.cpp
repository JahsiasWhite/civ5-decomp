// c5d-model: Gemini 3.8 Flash
class Host_0076e940 {
public:
    char pad[0x18c];
    char m_arr[0x40];
    // src: GUESS (confidence: high) [0x0076e940]
    void __thiscall SetByte(unsigned int idx, char val);
};

void Host_0076e940::SetByte(unsigned int idx, char val) {
    if (idx <= 0x3f) {
        m_arr[idx] = val;
    }
}
