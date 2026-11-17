// c5d-model: Gemini 4 Hydrogen
class Host_008eb180 {
public:
    int m_f0;
    int m_f4;
    char pad[0x54];
    int m_f5c;
    // src: GUESS (confidence: high) [0x008eb180]
    bool __thiscall HasAny() const;
};

bool __thiscall Host_008eb180::HasAny() const {
    return m_f0 != 0 || m_f4 != 0 || m_f5c != 0;
}
