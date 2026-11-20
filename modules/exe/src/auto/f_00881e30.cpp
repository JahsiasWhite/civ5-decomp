// src: GUESS (confidence: low)
struct Target_00881e30
{
    virtual void V0();
    virtual void V1();
    virtual void V2();
    // src: GUESS (confidence: low)
    virtual void V3();

    char m_pad04[0x14];      // +0x04
    unsigned char m_flags18; // +0x18
};

// src: GUESS (confidence: low) [0x00881e30]
struct Unk_00881e30
{
    int m_pad00;               // +0x00
    Target_00881e30** m_begin; // +0x04
    Target_00881e30** m_end;   // +0x08

    // src: GUESS (confidence: high) [0x00881e30]
    void Update_00881e30();
};

// src: GUESS (confidence: high) [0x00881e30]
void Unk_00881e30::Update_00881e30()
{
    for (Target_00881e30** it = m_begin; it != m_end; ++it)
    {
        Target_00881e30* t = *it;
        if (t->m_flags18 & 4)
            t->V3();
    }
}
