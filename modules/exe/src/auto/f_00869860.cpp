// src: GUESS (confidence: low) [0x00869860]
struct Unk_00869860
{
    void* m_p00;           // +0x00
    int m_f04;             // +0x04
    unsigned char m_f08;   // +0x08

    // src: GUESS (confidence: high) [0x00869860]
    bool Set_00869860(void* p, int f04, unsigned char f08);
};

// src: GUESS (confidence: high) [0x00869860]
bool Unk_00869860::Set_00869860(void* p, int f04, unsigned char f08)
{
    if (!p)
        return false;
    m_p00 = p;
    m_f04 = f04;
    m_f08 = f08;
    return true;
}
