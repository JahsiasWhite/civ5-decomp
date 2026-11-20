// src: GUESS (confidence: low)
struct Target_0086c590
{
    virtual void V0(); virtual void V1(); virtual void V2(); virtual void V3();
    virtual void V4(); virtual void V5(); virtual void V6(); virtual void V7();
    virtual void V8();
    // src: GUESS (confidence: low)
    virtual void V9(float val);
};

// src: GUESS (confidence: low) [0x0086c590]
struct Unk_0086c590
{
    char m_pad00[0x9c];      // +0x00
    Target_0086c590* m_p9c;  // +0x9c
    float m_fa0;             // +0xa0

    // src: GUESS (confidence: high) [0x0086c590]
    void SetFloat_0086c590(float val);
};

// src: GUESS (confidence: high) [0x0086c590]
void Unk_0086c590::SetFloat_0086c590(float val)
{
    m_fa0 = val;
    m_p9c->V9(val);
}
