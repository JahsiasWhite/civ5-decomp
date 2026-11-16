// c5d-model: Gemini 3.8 Flash
class Class_009184e0 {
public:
    float m_f0;
    float m_f4;
    char pad[4];
    int m_flag;
    // src: GUESS (confidence: high) [0x009184e0]
    float __thiscall GetFloat();
};
float Class_009184e0::GetFloat() {
    if (m_flag) return m_f4;
    return m_f0;
}
