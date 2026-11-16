// c5d-model: Gemini 4 Hydrogen
class Class_0064eb90 {
public:
    char m_arr[4];
    // src: GUESS (confidence: high) [0x0064eb90]
    void __thiscall ClearSlot(unsigned int idx);
};
void Class_0064eb90::ClearSlot(unsigned int idx) {
    if (idx < 4) {
        m_arr[idx] = 0;
    }
}
