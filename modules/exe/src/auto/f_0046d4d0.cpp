// src: GUESS (confidence: low)
struct UnkTarget_0046d4d0
{
    virtual void Vfunc0();
    virtual void Vfunc1();
    virtual void Vfunc2();
    virtual void Vfunc3();
    virtual void Vfunc4();
    virtual void Vfunc5();
    virtual int Vfunc6();
};

// src: GUESS (confidence: low) [0x0046d4d0]
struct Unk_0046d4d0
{
    char m_pad00[0x0c];            // +0x00
    UnkTarget_0046d4d0* m_p0c;     // +0x0c
    char m_pad10[0x218];           // +0x10
    int m_state228;                // +0x228

    // src: GUESS (confidence: high) [0x0046d4d0]
    int DispatchIfReady_0046d4d0();
};

// src: GUESS (confidence: high) [0x0046d4d0]
int Unk_0046d4d0::DispatchIfReady_0046d4d0()
{
    if (m_state228 == 2 && m_p0c)
        return m_p0c->Vfunc6();
    return 0;
}
