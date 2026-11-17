// c5d-model: Gemini 4 Hydrogen
// src: GUESS (confidence: high)
class Sub_0053b790 {
public:
    virtual ~Sub_0053b790();
};

class Host_0053b790 {
public:
    char pad[0x10];
    Sub_0053b790* m_sub;
    // src: GUESS (confidence: high) [0x0053b790]
    void __thiscall Release();
};

void __thiscall Host_0053b790::Release() {
    if (m_sub) {
        delete m_sub;
        m_sub = 0;
    }
}
