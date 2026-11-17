// c5d-model: Gemini 4 Hydrogen
class Class_0066d1d0 {
public:
    char pad[0x18];
    char* m_ptr;
    unsigned int m_count;
    // src: GUESS (confidence: high) [0x0066d1d0]
    char* __thiscall GetOffset();
};
char* Class_0066d1d0::GetOffset() {
    if (m_count > 0) return m_ptr + 0xe0;
    return 0;
}
