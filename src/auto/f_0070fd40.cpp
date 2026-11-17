// c5d-model: Gemini 4 Hydrogen
class Host_0070fd40 {
public:
    char pad[0x290];
    int m_a;
    int m_b;
    // src: GUESS (confidence: high) [0x0070fd40]
    int __thiscall SelectVal(int mode) const;
};

int Host_0070fd40::SelectVal(int mode) const {
    if (mode == 2) {
        return m_b;
    }
    return m_a;
}
