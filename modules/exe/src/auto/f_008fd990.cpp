// c5d-model: Gemini 4 Hydrogen
class Host_008fd990 {
public:
    char pad[0x21c];
    int m_a;
    int m_b;
    // src: GUESS (confidence: high) [0x008fd990]
    void __thiscall SetPair(int a, int b);
};

void Host_008fd990::SetPair(int a, int b) {
    m_a = a;
    m_b = b;
}
