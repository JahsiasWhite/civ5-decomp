// True when some entry has none of the flags 0x4000214 set.

// src: GUESS (confidence: low)
struct Entry_00639ba0
{
    char m_pad0[0xb8];
    // src: GUESS (confidence: low)
    unsigned int m_flags;
    char m_padbc[0x158 - 0xbc];
};

// src: GUESS (confidence: low)
struct Table_00639ba0
{
    char m_pad0[0x30];
    // src: GUESS (confidence: low)
    int m_count;
    // src: GUESS (confidence: low)
    Entry_00639ba0 m_entries[1];
};

// src: GUESS (confidence: low) [0x00639ba0]
bool HasUnflaggedEntry_00639ba0(const Table_00639ba0* table)
{
    for (int i = 0; i < table->m_count; ++i)
    {
        if (!(table->m_entries[i].m_flags & 0x4000214))
            return true;
    }
    return false;
}
