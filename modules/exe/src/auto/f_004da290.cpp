// src: GUESS (confidence: low)
struct Elem136_004da290
{
    int m_id;            // +0x00
    char m_pad04[0x84];  // +0x04
};

// src: GUESS (confidence: low) [0x004da290]
struct Unk_004da290
{
    char m_pad00[0xd8];          // +0x00
    Elem136_004da290 m_arr[7];   // +0xd8

    // src: GUESS (confidence: high) [0x004da290]
    int Find_004da290(int id);
};

// src: GUESS (confidence: high) [0x004da290]
int Unk_004da290::Find_004da290(int id)
{
    for (unsigned int i = 0; i < 7; ++i)
    {
        if (m_arr[i].m_id == id)
            return (int)i;
    }
    return -1;
}
