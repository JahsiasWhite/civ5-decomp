// c5d-model: Gemini 3.8 Flash
class Class_0090ea00 {
public:
    char pad[0x98];
    int m_flags;
    // src: GUESS (confidence: high) [0x0090ea00]
    void __thiscall SetFlags(int mask);
};
void Class_0090ea00::SetFlags(int mask) {
    m_flags |= mask;
}
