// c5d-model: Gemini 4 Hydrogen
class Host_008ed410 {
public:
    char pad[0xbc];
    float m_val;
    // src: GUESS (confidence: high) [0x008ed410]
    float __thiscall ExchangeFloat(float v);
};

float Host_008ed410::ExchangeFloat(float v) {
    float old = m_val;
    m_val = v;
    return old;
}
