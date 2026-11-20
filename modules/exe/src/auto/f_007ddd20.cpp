// src: GUESS (confidence: low)
struct Elem56_007ddd20
{
    char m_pad[28];
};

// src: GUESS (confidence: low) [0x007ddd20]
struct Unk_007ddd20
{
    char m_pad00[0x198];     // +0x00
    Elem56_007ddd20* m_begin;// +0x198
    Elem56_007ddd20* m_end;  // +0x19c

    // src: GUESS (confidence: high) [0x007ddd20]
    int GetCount_007ddd20();
};

// src: GUESS (confidence: high) [0x007ddd20]
int Unk_007ddd20::GetCount_007ddd20()
{
    return (int)(m_end - m_begin);
}
