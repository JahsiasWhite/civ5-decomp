// src: GUESS (confidence: low)
struct Base1_00404950
{
    virtual void V0() {}
    // src: GUESS (confidence: low)
    virtual void V1(int a, int b) {}
};

// src: GUESS (confidence: low)
struct Base2_00404950
{
    virtual void V2_0() {}
};

// src: GUESS (confidence: low)
struct Derived_00404950 : Base1_00404950, Base2_00404950
{
    char m_pad08[0x124];   // +0x08
    int m_f12c;            // +0x12c
};

// src: GUESS (confidence: high) [0x00404950]
void __stdcall CallV1_00404950(Base2_00404950* b)
{
    Derived_00404950* d = static_cast<Derived_00404950*>(b);
    d->V1(d->m_f12c, 0);
}
