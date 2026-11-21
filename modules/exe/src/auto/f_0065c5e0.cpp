// src: GUESS (confidence: low)
struct UnkCell4_0065c5e0
{
    unsigned short m_w;
    unsigned char m_b;
    unsigned char m_pad;
};

// src: GUESS (confidence: low)
struct UnkGrid_0065c5e0
{
    char m_pad[0x2c8];
    UnkCell4_0065c5e0 m_cells[255][256];

    void ResetGrid_0065c5e0();
};

// src: GUESS (confidence: medium) [0x0065c5e0]
void UnkGrid_0065c5e0::ResetGrid_0065c5e0()
{
    for (int y = 0; y < 255; ++y)
    {
        for (int x = 0; x < 255; ++x)
        {
            m_cells[y][x].m_w = 0xffff;
            m_cells[y][x].m_b = 0;
        }
    }
}
