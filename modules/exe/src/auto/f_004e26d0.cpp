// Finds the attached item whose key matches, or null.

// src: GUESS (confidence: low)
struct Item_00712370
{
    // src: GUESS (confidence: low)
    int m_key;
};

// src: GUESS (confidence: low)
struct Entry_00712370
{
    char m_pad0[0x84];
    // src: GUESS (confidence: low)
    Item_00712370* m_item;
};

// src: GUESS (confidence: low)
struct Table_00712370
{
    // src: GUESS (confidence: low) [0x00712370]
    Item_00712370* Find(int key);

    char m_pad0[8];
    // src: GUESS (confidence: low)
    Entry_00712370* m_entries;
    // src: GUESS (confidence: low)
    unsigned int m_count;
};

Item_00712370* Table_00712370::Find(int key)
{
    if (m_entries)
    {
        for (unsigned int i = 0; i < m_count; ++i)
        {
            Item_00712370* item = m_entries[i].m_item;
            if (item && item->m_key == key)
            {
                return item;
            }
        }
    }
    return 0;
}
