// c5d-model: Gemini 4 Hydrogen
extern "C" char aEmpty_00b6445e[];
class Class_008337a0 {
public:
    char** m_ptr;
    // src: GUESS (confidence: high) [0x008337a0]
    char* __thiscall GetStr();
};
char* Class_008337a0::GetStr() {
    if (m_ptr) return *m_ptr;
    return aEmpty_00b6445e;
}
