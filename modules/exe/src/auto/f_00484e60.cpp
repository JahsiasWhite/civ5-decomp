// src: GUESS (confidence: low)
struct Target_00484e60
{
    virtual void V0(); virtual void V1(); virtual void V2(); virtual void V3();
    virtual void V4(); virtual void V5(); virtual void V6(); virtual void V7();
    virtual void V8(); virtual void V9(); virtual void V10(); virtual void V11();
    virtual void V12(); virtual void V13(); virtual void V14(); virtual void V15();
    virtual void V16(); virtual void V17(); virtual void V18();
    // src: GUESS (confidence: low)
    virtual int V19(int b, void* a);
};

// src: GUESS (confidence: low) [0x00484e60]
struct Unk_00484e60
{
    char m_pad00[0x10];     // +0x00
    int m_f10;              // +0x10
    Target_00484e60* m_p14; // +0x14

    // src: GUESS (confidence: high) [0x00484e60]
    int Read_00484e60(void* a, int b);
};

// src: GUESS (confidence: high) [0x00484e60]
int Unk_00484e60::Read_00484e60(void* a, int b)
{
    if (m_p14 && a && b)
    {
        int n = m_p14->V19(b, a);
        m_f10 += n;
        return n;
    }
    return 0;
}
