// c5d-model: Gemini 3.8 Flash
class Host_00500010 {
public:
    char pad[0x20c];
    int m_arr[0x40];
    // src: GUESS (confidence: high) [0x00500010]
    void __thiscall SetVal(unsigned int idx, int val);
};

void Host_00500010::SetVal(unsigned int idx, int val) {
    if (idx <= 0x3f) {
        m_arr[idx] = val;
    }
}
