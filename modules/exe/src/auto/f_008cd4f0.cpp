// c5d-model: Gemini 4 Hydrogen
// src: GUESS (confidence: high)
class Host_008cd4f0 {
public:
    void Reset();
    int m_pad00[2];
    int m_field08;
    int m_pad0c[2];
    int m_field14;
    int m_field18;
    int m_field1c;
    unsigned short m_field20;
    unsigned short m_pad22;
    int m_pad24[5];
    int m_field38;
    int m_field3c;
};

// src: GUESS (confidence: high) [0x008cd4f0]
void Host_008cd4f0::Reset() {
    m_field18 = m_field14;
    m_field1c = 0;
    m_field08 = 0;
    m_field38 = 0;
    m_field20 = 0;
    m_field3c = 0;
}
