// c5d-model: Gemini 4 Hydrogen
extern "C" char aDefault_00a498c2[];
struct Inner_00553580 {
    int pad;
    char* str;
};
class Class_00553580 {
public:
    char pad[0x58];
    Inner_00553580* m_inner;
    // src: GUESS (confidence: high) [0x00553580]
    char* __thiscall GetStr();
};
char* Class_00553580::GetStr() {
    if (m_inner) return m_inner->str;
    return aDefault_00a498c2;
}
