// c5d-model: Gemini 3.8 Flash
struct Inner_00672d20 {
    char pad[8];
    int val;
};
class Class_00672d20 {
public:
    char pad[0x78];
    Inner_00672d20* m_inner;
    // src: GUESS (confidence: high) [0x00672d20]
    int __thiscall GetVal();
};
int Class_00672d20::GetVal() {
    if (m_inner) return m_inner->val;
    return 0;
}
