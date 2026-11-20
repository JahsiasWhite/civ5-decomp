// src: GUESS (confidence: low)
struct Pair8_007ba800
{
    int m_a;
    int m_b;
};

// src: GUESS (confidence: low) [0x007ba800]
struct Unk_007ba800
{
    virtual void V0(); virtual void V1(); virtual void V2(); virtual void V3();
    virtual void V4(); virtual void V5(); virtual void V6();
    // src: GUESS (confidence: low)
    virtual void V7(const Pair8_007ba800* p);

    // src: GUESS (confidence: high) [0x007ba800]
    void CallV7_007ba800(int a, int b);
};

// src: GUESS (confidence: high) [0x007ba800]
void Unk_007ba800::CallV7_007ba800(int a, int b)
{
    Pair8_007ba800 p;
    p.m_a = a;
    p.m_b = b;
    V7(&p);
}
