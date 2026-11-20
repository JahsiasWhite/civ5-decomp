// src: GUESS (confidence: low)
struct Target_00485020
{
    virtual void V0(); virtual void V1(); virtual void V2(); virtual void V3();
    virtual void V4(); virtual void V5(); virtual void V6(); virtual void V7();
    virtual void V8();
    // src: GUESS (confidence: low)
    virtual void V9(int val);
    virtual void V10(); virtual void V11(); virtual void V12(); virtual void V13();
    virtual void V14();
    // src: GUESS (confidence: low)
    virtual int V15();
};

// src: GUESS (confidence: low) [0x00485020]
struct Unk_00485020
{
    char m_pad00[0x14];     // +0x00
    Target_00485020* m_p14; // +0x14

    // src: GUESS (confidence: high) [0x00485020]
    void Forward_00485020();
};

// src: GUESS (confidence: high) [0x00485020]
void Unk_00485020::Forward_00485020()
{
    if (m_p14)
        m_p14->V9(m_p14->V15());
}
