// c5d-model: Gemini 3.8 Flash
class Class_00527ee0 {
public:
    char pad[0x18];
    char* m_ptr;
    // src: GUESS (confidence: high) [0x00527ee0]
    char* __thiscall GetOffset();
};
char* Class_00527ee0::GetOffset() {
    if (m_ptr) return m_ptr + 0x80;
    return 0;
}
