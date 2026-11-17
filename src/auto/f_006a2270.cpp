// c5d-model: Gemini 4 Hydrogen
class Host_006a2270 {
public:
    char pad[0x64];
    float m_val;
    // src: GUESS (confidence: high) [0x006a2270]
    void __thiscall SetNonNegative(float v);
};

void Host_006a2270::SetNonNegative(float v) {
    m_val = (0.0f > v) ? 0.0f : v;
}
