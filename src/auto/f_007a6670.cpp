// c5d-model: Gemini 4 Hydrogen
struct Inner_007a6670 {
    char pad[0x89];
    char flag;
};
class Class_007a6670 {
public:
    Inner_007a6670* m_inner;
    // src: GUESS (confidence: high) [0x007a6670]
    char __thiscall GetFlag();
};
char Class_007a6670::GetFlag() {
    if (m_inner) return m_inner->flag;
    return 0;
}
