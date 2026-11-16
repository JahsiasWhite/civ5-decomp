// c5d-model: Gemini 4 Hydrogen
extern "C" char aDefault_009dea08[];
class Class_007e0b40 {
public:
    char pad[0xc];
    char* m_ptr;
    // src: GUESS (confidence: high) [0x007e0b40]
    char* __thiscall GetOffset();
};
char* Class_007e0b40::GetOffset() {
    if (m_ptr) return m_ptr + 4;
    return aDefault_009dea08;
}
