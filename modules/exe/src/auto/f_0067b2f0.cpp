// src: GUESS (confidence: low)
struct UnkListener_0067b2f0
{
    virtual void V0() {}
    virtual void V1() {}
    virtual void V2() {}
    virtual void V3() {}
    virtual void V4() {}
    virtual void V5() {}
    virtual void V6() {}
    virtual void V7() {}
    virtual void V8() {}
    virtual void V9() {}
    virtual void V10() {}
    virtual void V11() {}
    virtual void V12() {}
    virtual void V13() {}
    virtual void V14() {}
    virtual void V15() {}
    virtual void V16() {}
    virtual void V17() {}
    virtual void V18() {}
    virtual void V19() {}
    virtual void V20(int a) {}
};

// src: GUESS (confidence: low)
struct UnkObj_0067b2f0
{
    char m_pad00[0x5a0];
    void* m_a;
    void* m_b;
    UnkListener_0067b2f0* m_c;
    char m_pad5ac[0x10];
    unsigned int m_flags;

    void ClearPtr_0067b2f0(void* p);
};

// src: GUESS (confidence: medium) [0x0067b2f0]
void UnkObj_0067b2f0::ClearPtr_0067b2f0(void* p)
{
    if (!p)
        return;
    if (p == m_a)
        m_a = 0;
    if (p == m_b)
    {
        m_b = 0;
        m_c->V20(1);
        m_flags &= ~1u;
    }
}
