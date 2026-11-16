// c5d-model: Gemini 3.8 Flash
extern "C" char aDefault_00aa1a40[];
class Class_00916110 {
public:
    char pad[0x38];
    char* m_str;
    // src: GUESS (confidence: high) [0x00916110]
    char* __thiscall GetStr();
};
char* Class_00916110::GetStr() {
    if (!m_str) return aDefault_00aa1a40;
    return m_str;
}
