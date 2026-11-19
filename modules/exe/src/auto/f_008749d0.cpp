// c5d-model: Gemini 4 Hydrogen
class Class_0090e9f0 {
public:
    char pad[0x98];
    int m_flags;
    // src: GUESS (confidence: high) [0x0090e9f0]
    char __thiscall HasFlag(int mask);
};
char Class_0090e9f0::HasFlag(int mask) {
    return (m_flags & mask) != 0;
}
