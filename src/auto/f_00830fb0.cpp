// c5d-model: Gemini 3.8 Flash
// src: GUESS (confidence: low)
class Unk_00830fb0 {
public:
    char pad[0x18];
    unsigned int m_field18;
    unsigned int m_field1c;
    // src: GUESS (confidence: high) [0x00830fb0]
    int IsGreaterOrEqual();
};

int Unk_00830fb0::IsGreaterOrEqual() {
    return m_field18 >= m_field1c;
}
