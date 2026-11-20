// src: GUESS (confidence: low)
struct UnkSubItem64_004fc720
{
    int m_f00;
    int m_id;
    int m_pad[14];
};

// src: GUESS (confidence: low)
struct UnkGroup128_004fc720
{
    UnkSubItem64_004fc720 items[2];
};

// src: GUESS (confidence: low)
struct UnkContainer_004fc720
{
    char m_pad[0x6c];
    UnkGroup128_004fc720 m_groups[1];

    UnkSubItem64_004fc720* FindSubItem_004fc720(int groupIdx, int id);
};

// src: GUESS (confidence: medium) [0x004fc720]
UnkSubItem64_004fc720* UnkContainer_004fc720::FindSubItem_004fc720(int groupIdx, int id)
{
    int i = 0;
    UnkSubItem64_004fc720* p = &m_groups[groupIdx].items[0];
    while (i < 2)
    {
        if (p->m_id == id)
            return p;
        ++i;
        ++p;
    }
    return 0;
}
