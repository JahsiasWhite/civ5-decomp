// c5d-model: Gemini 4 Hydrogen
// src: GUESS (confidence: high)
class Sub_00671130 {
public:
    virtual ~Sub_00671130();
};

class Host_00671130 {
public:
    char pad[8];
    Sub_00671130* m_sub;
    // src: GUESS (confidence: high) [0x00671130]
    void __thiscall Release();
};

void __thiscall Host_00671130::Release() {
    if (m_sub) {
        delete m_sub;
        m_sub = 0;
    }
}
