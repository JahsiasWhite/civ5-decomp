// src: GUESS (confidence: low)
struct UnkItem588_00885ce0
{
    char m_active;
    char m_pad[0x24b];
};

// src: GUESS (confidence: low)
struct UnkManager_00885ce0
{
    int m_pad00[2];
    int m_count;
    char m_pad0c[0x50];
    UnkItem588_00885ce0* m_items;

    int FindFirstActive_00885ce0();
};

// src: GUESS (confidence: medium) [0x00885ce0]
int UnkManager_00885ce0::FindFirstActive_00885ce0()
{
    for (int i = 0; i < m_count; ++i)
    {
        if (m_items[i].m_active)
            return i;
    }
    return -1;
}
