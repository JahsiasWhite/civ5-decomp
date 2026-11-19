// c5d-model: Gemini 4 Hydrogen
class Host_005309f0 {
public:
    float m_limit;
    char pad[0x60];
    float m_val;
    unsigned char m_flag;
    // src: GUESS (confidence: high) [0x005309f0]
    int __thiscall Check() const;
};

int Host_005309f0::Check() const {
    if (!m_flag || m_val > m_limit) {
        return 1;
    }
    return 0;
}
