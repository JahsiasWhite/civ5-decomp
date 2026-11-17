// c5d-model: Gemini 3.8 Flash

// src: GUESS (confidence: high) [0x007e09c0]
class ISubTarget_007e09c0 {
public:
    virtual void D0(); virtual void D1(); virtual void D2(); virtual void D3();
    virtual void D4(); virtual void D5(); virtual void D6(); virtual void D7();
    virtual void D8(); virtual void D9();
    virtual void Execute();
};

// src: GUESS (confidence: high) [0x007e09c0]
class Host_007e09c0 {
public:
    char m_pad[0x30];
    int m_flag;
    ISubTarget_007e09c0 m_sub;
    void Forward();
};

// src: GUESS (confidence: high) [0x007e09c0]
void Host_007e09c0::Forward()
{
    m_flag = 0;
    m_sub.Execute();
}
