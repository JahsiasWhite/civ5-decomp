// src: GUESS (confidence: low)
struct Vec2_00664f60
{
    int m_x;
    int m_y;

    // src: GUESS (confidence: low)
    Vec2_00664f60& operator=(const Vec2_00664f60& other)
    {
        m_x = other.m_x;
        m_y = other.m_y;
        return *this;
    }
};

// src: GUESS (confidence: low)
struct Source_00664f60
{
    virtual void V0(); virtual void V1(); virtual void V2(); virtual void V3();
    virtual void V4(); virtual void V5(); virtual void V6(); virtual void V7();
    virtual void V8(); virtual void V9(); virtual void V10(); virtual void V11();
    virtual void V12(); virtual void V13(); virtual void V14(); virtual void V15();
    virtual void V16(); virtual void V17(); virtual void V18(); virtual void V19();
    virtual void V20(); virtual void V21(); virtual void V22(); virtual void V23();
    virtual void V24(); virtual void V25(); virtual void V26(); virtual void V27();
    virtual void V28(); virtual void V29(); virtual void V30(); virtual void V31();
    virtual void V32(); virtual void V33(); virtual void V34(); virtual void V35();
    virtual void V36();
    // src: GUESS (confidence: low)
    virtual Vec2_00664f60 __stdcall GetVec37();
};

// src: GUESS (confidence: low) [0x00664f60]
struct Unk_00664f60
{
    char m_pad00[0x9c];  // +0x00
    Vec2_00664f60 m_v9c; // +0x9c

    // src: GUESS (confidence: high) [0x00664f60]
    void Update_00664f60(Source_00664f60* src);
};

// src: GUESS (confidence: high) [0x00664f60]
void Unk_00664f60::Update_00664f60(Source_00664f60* src)
{
    m_v9c = src->GetVec37();
}
