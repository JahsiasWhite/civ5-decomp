// c5d-model: Gemini 3.8 Flash
// src: GUESS (confidence: low)
class Unk_008cfd50 {
public:
    int pad0;
    int m_field4;
    char m_flag;
    // src: GUESS (confidence: high) [0x008cfd50]
    int SetAndGet(int a, int b);
};

int Unk_008cfd50::SetAndGet(int a, int b) {
    int res = m_field4;
    m_flag = 1;
    return res;
}
