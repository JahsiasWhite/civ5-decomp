// src: GUESS (confidence: low)
struct Grid_005a96c0
{
    char m_pad[0xcc];
    int m_cells[200][200];

    // src: GUESS (confidence: high) [0x005a96c0]
    void Clear();
};

void Grid_005a96c0::Clear()
{
    for (int x = 0; x < 200; ++x)
    {
        for (int y = 0; y < 200; ++y)
        {
            m_cells[y][x] = 0;
        }
    }
}
