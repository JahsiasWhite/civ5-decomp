// Finds the 48-byte entry with the given key in the owned list; null when
// there's none.

// src: GUESS (confidence: low)
struct Entry_008eb640
{
    // src: GUESS (confidence: low)
    int m_key;
    int m_data[11];
};

// src: GUESS (confidence: low)
struct EntryList_008eb640
{
    // src: GUESS (confidence: low)
    Entry_008eb640* m_entries;
    // src: GUESS (confidence: low)
    unsigned int m_count;
};

// src: GUESS (confidence: low)
class Owner_008eb640
{
public:
    // src: GUESS (confidence: low) [0x008eb640]
    Entry_008eb640* Find(int key) const;

    int m_00;
    // src: GUESS (confidence: low)
    EntryList_008eb640* m_list;
};

Entry_008eb640* Owner_008eb640::Find(int key) const
{
    EntryList_008eb640* list = m_list;
    for (unsigned int i = 0; i < list->m_count; ++i)
    {
        if (list->m_entries[i].m_key == key)
            return &list->m_entries[i];
    }
    return 0;
}
