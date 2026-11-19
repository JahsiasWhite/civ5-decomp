// src: GUESS (confidence: low)
struct Entry_0061af40
{
    char m_pad00[0x2d3c];
    char m_b2d3c;
    char m_b2d3d;
    char m_pad2d3e[9];
    char m_b2d47;
    char m_pad2d48[0x18];
};

// src: GUESS (confidence: low)
struct Table_0061af40
{
    char m_pad[0x270];
    Entry_0061af40 m_entries[1];

    // src: GUESS (confidence: high) [0x0061af40]
    int CheckEntry(int idx);
};

int Table_0061af40::CheckEntry(int idx)
{
    Entry_0061af40* e = &m_entries[idx];
    if (e->m_b2d3d == 0 && e->m_b2d47 == 0 && e->m_b2d3c != 0)
    {
        return 1;
    }
    return 0;
}
