// src: GUESS (confidence: low) [0x00691a80]
struct Unk_00691a80
{
    virtual void V0(); virtual void V1(); virtual void V2(); virtual void V3();
    virtual void V4(); virtual void V5(); virtual void V6(); virtual void V7();
    virtual void V8(); virtual void V9(); virtual void V10(); virtual void V11();
    virtual void V12(); virtual void V13(); virtual void V14(); virtual void V15();
    virtual void V16(); virtual void V17(); virtual void V18(); virtual void V19();
    virtual void V20(); virtual void V21(); virtual void V22(); virtual void V23();
    // src: GUESS (confidence: low)
    virtual char* GetBase24();

    char m_pad04[0x174];  // +0x04
    int m_flag178;        // +0x178

    // src: GUESS (confidence: high) [0x00691a80]
    void* GetPtr_00691a80();
};

// src: GUESS (confidence: high) [0x00691a80]
void* Unk_00691a80::GetPtr_00691a80()
{
    return (GetBase24() + 0x17c) + (m_flag178 ? 0x174 : 0);
}
