// c5d-model: Gemini 3.8 Flash
// src: GUESS (confidence: low)
class Unk_008eb1a0 {
public:
    char pad[0x30];
    int m_field30;
    char pad2[4];
    int m_field38;
    // src: GUESS (confidence: high) [0x008eb1a0]
    int Calc();
};

int Unk_008eb1a0::Calc() {
    return (m_field38 << 6) + m_field30;
}
