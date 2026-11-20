// src: GUESS (confidence: low) [0x005fa450]
struct Unk_005fa450
{
    char m_pad00[0x834];             // +0x00
    unsigned char m_grid[128][128];  // +0x834

    // src: GUESS (confidence: high) [0x005fa450]
    void ClearGrid_005fa450();
};

// src: GUESS (confidence: high) [0x005fa450]
void Unk_005fa450::ClearGrid_005fa450()
{
    for (int col = 0; col < 128; ++col)
    {
        for (int row = 0; row < 128; ++row)
            m_grid[row][col] = 0;
    }
}
